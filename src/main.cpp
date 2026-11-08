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

    cpu.DumpMemory(memory, 0x0000, 32);

    printf("FLAGS=%02X\n", cpu.GetFlags());
}