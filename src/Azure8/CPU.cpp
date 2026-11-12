#include "CPU.h"
#include "Memory.h"

#include <cstdio>

namespace
{
    //-------------------------------------------------
    // Opcodes
    //-------------------------------------------------

    constexpr u8 OPCODE_NOP = 0x00;

    constexpr u8 OPCODE_MOV = 0x10;
    constexpr u8 OPCODE_LOAD = 0x11;
    constexpr u8 OPCODE_STORE = 0x12;

    constexpr u8 OPCODE_PUSH = 0x20;

    constexpr u8 OPCODE_HLT = 0xFF;

    //-------------------------------------------------
    // Stack
    //-------------------------------------------------

    constexpr u16 STACK_BOTTOM = 0xFE00;
    constexpr u16 STACK_TOP = 0xFFFF;
}
//-----------------------------------------------------
// Reset
//-----------------------------------------------------

void CPU::Reset()
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;

    PC = 0x0000;
    SP = STACK_TOP;

    FLAGS = 0;

    m_Halted = false;

    m_StackOverflow = false;
    m_StackUnderflow = false;
}

//-----------------------------------------------------
// IsHalted
//-----------------------------------------------------

bool CPU::IsHalted() const
{
    return m_Halted;
}

//-----------------------------------------------------
// GetSP
//-----------------------------------------------------

u16 CPU::GetSP() const
{
    return SP;
}

//-----------------------------------------------------
// GetFlags
//-----------------------------------------------------

u8 CPU::GetFlags() const
{
    return FLAGS;
}

//-----------------------------------------------------
// GetRegister
//-----------------------------------------------------

u8& CPU::GetRegister(u8 reg)
{
    switch (reg)
    {
        case 0x00: return A;
        case 0x01: return B;
        case 0x02: return C;
        case 0x03: return D;
    
        default:
            return A;
    }
}

//-----------------------------------------------------
// HasStackOverflow
//-----------------------------------------------------

bool CPU::HasStackOverflow() const
{
    return m_StackOverflow;
}

//-----------------------------------------------------
// HasStackUnderflow
//-----------------------------------------------------

bool CPU::HasStackUnderflow() const
{
    return m_StackUnderflow;
}

//-----------------------------------------------------
// SetFlag
//-----------------------------------------------------

void CPU::SetFlag(u8 flag)
{
    FLAGS |= flag;
}

//-----------------------------------------------------
// ClearFlag
//-----------------------------------------------------

void CPU::ClearFlag(u8 flag)
{
    FLAGS &= ~flag;
}

//-----------------------------------------------------
// IsFlagSet
//-----------------------------------------------------

bool CPU::IsFlagSet(u8 flag) const
{
    return (FLAGS & flag) != 0;
}

//-----------------------------------------------------
// UpdateZeroFlag
//-----------------------------------------------------

void CPU::UpdateZeroFlag(u8 value)
{
    if (value == 0)
        SetFlag(FLAG_ZERO);
    else
        ClearFlag(FLAG_ZERO);
}

//-----------------------------------------------------
// UpdateCarryFlag
//-----------------------------------------------------

void CPU::UpdateCarryFlag(bool carry)
{
    if (carry)
        SetFlag(FLAG_CARRY);
    else
        ClearFlag(FLAG_CARRY);
}

//-----------------------------------------------------
// UpdateNegativeFlag
//-----------------------------------------------------

void CPU::UpdateNegativeFlag(u8 value)
{
    if ((value & 0x80) != 0)
        SetFlag(FLAG_NEGATIVE);
    else
        ClearFlag(FLAG_NEGATIVE);
}

//-----------------------------------------------------
// UpdateOverflowFlag
//-----------------------------------------------------

void CPU::UpdateOverflowFlag(bool overflow)
{
    if (overflow)
        SetFlag(FLAG_OVERFLOW);
    else
        ClearFlag(FLAG_OVERFLOW);
}

//-----------------------------------------------------
// FetchByte
//-----------------------------------------------------

u8 CPU::FetchByte(Memory& memory)
{
    const u8 value = memory.Read8(PC);
    
    PC++;

    return value;
}

//-----------------------------------------------------
// Push8
//-----------------------------------------------------

void CPU::Push8(Memory& memory, u8 value)
{
    if (SP < STACK_BOTTOM)
    {
        printf("STACK OVERFLOW\n");

        m_StackOverflow = true;
        m_Halted = true;

        return;
    }

    memory.Write8(SP, value);
    SP--;
}

//-----------------------------------------------------
// Pop8
//-----------------------------------------------------

u8 CPU::Pop8(Memory& memory)
{
    if (SP >= STACK_TOP)
    {
        printf("STACK UNDERFLOW\n");

        m_StackUnderflow = true;
        m_Halted = true;

        return 0;
    }
    
    SP++;
    return memory.Read8(SP);
}

//-----------------------------------------------------
// Push16
//-----------------------------------------------------

void CPU::Push16(Memory& memory, u16 value)
{
    const u8 high = static_cast<u8>((value >> 8) & 0xFF);
    const u8 low = static_cast<u8>(value & 0xFF);

    Push8(memory, high);
    Push8(memory, low);
}

//-----------------------------------------------------
// Pop16
//-----------------------------------------------------

u16 CPU::Pop16(Memory& memory)
{
    const u8 low = Pop8(memory);
    const u8 high = Pop8(memory);

    return static_cast<u16>(low | (high << 8));
}

//-----------------------------------------------------
// DumpStack
//-----------------------------------------------------

void CPU::DumpStack(const Memory& memory, u16 count) const
{
    printf("\n========== STACK ==========\n");
    printf("SP = %04X\n\n", SP);

    u32 address = static_cast<u32>(SP + 1);

    for (u16 i = 0; i < count; i++)
    {
        if (address > STACK_TOP)
            break;

        printf("%04X : %02X", static_cast<u16>(address), memory.Read8(static_cast<u16>(address)));

        if (address == static_cast<u32>(SP + 1))
            printf(" <- TOP");

        printf("\n");
        address++;
    }
    printf("===========================\n");
}

//-----------------------------------------------------
// DumpRegisters
//-----------------------------------------------------

void CPU::DumpRegister() const
{
    printf("\n========== REGISTERS ==========\n");
    printf("A = %02X\n", A);
    printf("B = %02X\n", B);
    printf("C = %02X\n", C);
    printf("D = %02X\n", D);
    printf("PC = %04X\n", PC);
    printf("SP = %04X\n", SP);
    printf("FLAGS = %02X\n", FLAGS);
    printf("===============================\n");
}

//-----------------------------------------------------
// DumpMemory
//-----------------------------------------------------

void CPU::DumpMemory(const Memory& memory, u16 startAddress, u16 count) const
{
    printf("\n========== MEMORY ==========\n");

    for (u16 i = 0; i < count; i += 16)
    {
        const u16 address = startAddress + i;

        printf("%04X : ", address);

        for (u16 j = 0; j < 16; j++)
        {
            if ((i + j) >= count)
                break;

            printf("%02X ", memory.Read8(address + j));
        }
        printf("\n");
    }
    printf("============================\n");
}

//-----------------------------------------------------
// Step
//-----------------------------------------------------

void CPU::Step(Memory& memory)
{
    const u8 opcode = FetchByte(memory);

    printf("PC=%04X SP=%04X FLAGS=%02X OPCODE=%02X\n", static_cast<u16>(PC - 1), SP, FLAGS, opcode);

    switch (opcode)
    {
        case OPCODE_NOP:
        {
            break;
        }
        case OPCODE_MOV:
        {
            const u8 destination = FetchByte(memory);
            const u8 source = FetchByte(memory);

            GetRegister(destination) = GetRegister(source);
            break;
        }
        case OPCODE_LOAD:
        {
            const u8 reg = FetchByte(memory);
            const u8 low = FetchByte(memory);
            const u8 high = FetchByte(memory);

            const u16 address = static_cast<u16>(low | (high << 8));

            GetRegister(reg) = memory.Read8(address);
            break;
        }
        case OPCODE_STORE:
        {
            const u8 reg = FetchByte(memory);
            const u8 low = FetchByte(memory);
            const u8 high = FetchByte(memory);

            const u16 address = static_cast<u16>(low | (high << 8));

            memory.Write8(address, GetRegister(reg));
            break;
        }
        case OPCODE_PUSH:
        {
            const u8 reg = FetchByte(memory);

            Push8(memory, GetRegister(reg));
            break;
        }
        case OPCODE_HLT:
        {
            printf("CPU HALTED\n");

            m_Halted = true;
            break;
        }
        default:
        {
            printf("UNKNOWN OPCODE %02X\n", opcode);

            m_Halted = true;

            break;
        }
    }
}
