#include "Memory.h"

#include <cstring>

//-----------------------------------------------------
// Reset
//-----------------------------------------------------

void Memory::Reset()
{
    std::memset(m_RAM, 0, sizeof(m_RAM));
}

//-----------------------------------------------------
// Read8
//-----------------------------------------------------

u8 Memory::Read8(u16 address) const
{
    return m_RAM[address];
}

//-----------------------------------------------------
// Write8
//-----------------------------------------------------

void Memory::Write8(u16 address, u8 value)
{
    m_RAM[address] = value;
}

//-----------------------------------------------------
// Read16
//-----------------------------------------------------

u16 Memory::Read16(u16 address) const
{
    const u8 low = Read8(address);
    const u8 high = Read8(address + 1);

    return static_cast<u16>(low | (high << 8));
}

//-----------------------------------------------------
// Write16
//-----------------------------------------------------

void Memory::Write16(u16 address, u16 value)
{
    const u8 low = static_cast<u8>(value & 0xFF);
    const u8 high = static_cast<u8>((value >> 8) & 0xFF);

    Write8(address, low);
    Write8(address + 1, high);
}