#include "Memory.h"

#include <cstring>

void Memory::Reset()
{
    std::memset(m_RAM, 0, sizeof(m_RAM));
}

u8 Memory::Read8(u16 address) const
{
    return m_RAM[address];
}

void Memory::Write8(u16 address, u8 value)
{
    m_RAM[address] = value;
}