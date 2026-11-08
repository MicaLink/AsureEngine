#include "CPU.h"
#include "Memory.h"

#include <cstdio>

namespace
{
    //-------------------------------------------------
    // Opcodes
    //-------------------------------------------------

    constexpr u8 OPCODE_NOP = 0x00;
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
    const u8 hight = static_cast<u8>((value >> 8) & 0xFF);
    const u8 low = static_cast<u8>(value & 0xFF);

    Push8(memory, hight);
    Push8(memory, low);
}

//-----------------------------------------------------
// Pop16
//-----------------------------------------------------

u16 CPU::Pop16(Memory& memory)
{
    const u8 low = Pop8(memory);
    const u8 hight = Pop8(memory);

    return static_cast<u16>(low | (hight << 8));
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
// Step
//-----------------------------------------------------

void CPU::Step(Memory& memory)
{
    const u8 opcode = FetchByte(memory);

    printf("PC=%04X SP=%04X FFAGS=%02X OPCODE=%02X\n", static_cast<u16>(PC - 1), SP, FLAGS, opcode);

    switch (opcode)
    {
        case OPCODE_NOP:
            break;
    
        case OPCODE_HLT:
            printf("CPU HALTED\n");
            m_Halted = true;
            break;
        
        default:
            printf("UNKNOWN OPCODE %02X\n", opcode);
            m_Halted = true;
            break;
    }
}
