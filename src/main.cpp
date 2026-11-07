#include "Azure8/Emulator.h"
#include "Azure8/CPU.h"
#include "Azure8/Memory.h"

#include <cstdio>

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    Memory memory;
    CPU cpu;

    memory.Reset();
    cpu.Reset();

    for (u16 i = 0; i < 100; ++i)
    {
        cpu.Push16(memory, i);
    }

    for (u16 i = 0; i < 100; ++i)
    {
        cpu.Pop16(memory);
    }

    return 0;
}