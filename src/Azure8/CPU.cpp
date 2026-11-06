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

    FLAGS = 0;

    PC = 0x0000;

    SP = 0xFFFF;

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