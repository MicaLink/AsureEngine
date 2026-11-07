#pragma once

#include "../Core/Type.h"

class Memory;

//-----------------------------------------------------
// CPU
//-----------------------------------------------------

class CPU
{
public:
    CPU() = default;

    //-------------------------------------------------
    // Execution
    //-------------------------------------------------

    void Reset();
    void Step(Memory& memory);

    bool IsHalted() const;

    //-------------------------------------------------
    // Stack
    //-------------------------------------------------

    void Push8(Memory& memory, u8 value);
    u8 Pop8(Memory& memory);

    void Push16(Memory& memory, u16 value);
    u16 Pop16(Memory& memory);

    //-------------------------------------------------
    // Debug
    //-------------------------------------------------

    void DumpStack(const Memory& memory, u16 count = 16) const;

    //-------------------------------------------------
    // Status
    //-------------------------------------------------

    u16 GetSP() const;

    bool HasStackOverflow() const;
    bool HasStackUnderflow() const;


private:

    //-------------------------------------------------
    // Fetch
    //-------------------------------------------------

    u8 FetchByte(Memory& memory);
public:

    //-------------------------------------------------
    // Registers
    //-------------------------------------------------

    u8 A = 0;
    u8 B = 0;
    u8 C = 0;
    u8 D = 0;

    u16 PC = 0;
    u16 SP = 0;

    u8 FLAGS = 0;
private:

    //-------------------------------------------------
    // State
    //-------------------------------------------------

    bool m_Halted = false;

    bool m_StackOverflow = false;
    bool m_StackUnderflow = false;
};