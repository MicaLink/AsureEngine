#include "CPU.h"
#include "Memory.h"

#include <cstdio>

constexpr u8 OPCODE_NOP = 0x00;
constexpr u8 OPCODE_HLT = 0xFF;

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

    SP = 0xFFFF;
    
    FLAGS = 0;

    m_Halted = false;
}

//-----------------------------------------------------
// IsHalted
//-----------------------------------------------------

bool CPU::IsHalted() const
{
    return m_Halted;
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
    memory.Write8(SP, value);
    SP--;
}

//-----------------------------------------------------
// Pop8
//-----------------------------------------------------

u8 CPU::Pop8(Memory& memory)
{
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
// Step
//-----------------------------------------------------

void CPU::Step(Memory& memory)
{
    const u8 opcode = FetchByte(memory);

    printf("PC=%04X OPCODE=%02X\n", PC - 1, opcode);

    switch (opcode)
    {
        case OPCODE_NOP:
            break;
    
        case OPCODE_HLT:
            m_Halted = true;
            printf("CPU HALTED\n");
            break;
        
        default:
            printf("UNKNOWN OPCODE %02X\n", opcode);
            m_Halted = true;
            break;
    }
}
