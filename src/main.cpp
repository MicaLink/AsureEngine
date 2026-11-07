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