#pragma once

#include "../Core/Type.h"

class Memory;

//-----------------------------------------------------
// CPU
//-----------------------------------------------------

class CPU
{
public:
    void Reset();
    void Step(Memory& memory);

    bool IsHalted() const;
private:
    u8 FetchByte(Memory& memory);
public:
    u8 A = 0;
    u8 B = 0;
    u8 C = 0;
    u8 D = 0;

    u16 PC = 0;
    u16 SP = 0;

    u8 FLAGS = 0;
private:
    bool m_Halted = false;
};