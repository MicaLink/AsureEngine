#pragma once

#include "../Core/Type.h"

//-----------------------------------------------------
// FLAGS
//-----------------------------------------------------

constexpr u8 FLAG_ZERO = (1 << 0);
constexpr u8 FLAG_CARRY = (1 << 1);
constexpr u8 FLAG_NEGATIVE = (1 << 2);
constexpr u8 FLAG_OVERFLOW = (1 << 3);

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
    // Flags
    //-------------------------------------------------

    void SetFlag(u8 flag);
    void ClearFlag(u8 flag);

    bool IsFlagSet(u8 flag) const;

    void UpdateZeroFlag(u8 value);
    void UpdateCarryFlag(bool carry);
    void UpdateNegativeFlag(u8 value);
    void UpdateOverflowFlag(bool overflow);

    u8 GetFlags() const;

    //-------------------------------------------------
    // Debug
    //-------------------------------------------------

    void DumpStack(const Memory& memory, u16 count = 16) const;
    void DumpRegister() const;
    void DumpMemory(const Memory& memory, u16 startAddress, u16 count = 128) const;

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
private:

    //-------------------------------------------------
    // User Registers
    //-------------------------------------------------

    u8 A = 0;
    u8 B = 0;
    u8 C = 0;
    u8 D = 0;

    //-------------------------------------------------
    // System Registers
    //-------------------------------------------------

    u16 PC = 0;
    u16 SP = 0;

    u8 FLAGS = 0;
private:

    //-------------------------------------------------
    // CPU State
    //-------------------------------------------------

    bool m_Halted = false;

    bool m_StackOverflow = false;
    bool m_StackUnderflow = false;
};