#include "Azure8/Emulator.h"

#include <cstdio>

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    Emulator emulator;
    Memory memory;
    CPU cpu;

    memory.Reset();
    cpu.Reset();

    cpu.Push16(memory, 0x1111);
    cpu.Push16(memory, 0x2222);
    cpu.Push16(memory, 0x3333);

    printf("%04X\n", cpu.Pop16(memory));
    printf("%04X\n", cpu.Pop16(memory));
    printf("%04X\n", cpu.Pop16(memory));

    if (!emulator.LoadROM("roms/test.rom"))
    {
        printf("Unable to load ROM\n");
        getchar();
        return -1;
    }

    emulator.Run();

    getchar();
    
    return 0;
}