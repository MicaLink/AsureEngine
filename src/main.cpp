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

    printf("Initial SP : %04X\n", cpu.GetSP());

    cpu.Push8(memory, 0x11);

    printf("After Push8 : %04X\n", cpu.GetSP());

    cpu.Push16(memory, 0x1234);

    printf("After Push16 : %04X\n", cpu.GetSP());

    cpu.Pop16(memory);

    printf("After Pop16 : %04X\n", cpu.GetSP());

    cpu.Pop8(memory);

    printf("After Pop8 : %04X\n", cpu.GetSP());

    getchar();

    return 0;
}