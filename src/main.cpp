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

    cpu.Push8(memory, 0x11);
    cpu.Push8(memory, 0x22);
    cpu.Push8(memory, 0x33);

    cpu.DumpStack(memory);

    return 0;
}