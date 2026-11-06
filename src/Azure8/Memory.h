#pragma once

#include "../Core/Type.h"

constexpr u32 RAM_SIZE = 65536;

class Memory
{
public:
    void Reset();

    u8 Read8(u16 address) const;

    void Write8(u16 address, u8 value);

private:
    u8 m_RAM[RAM_SIZE];
};