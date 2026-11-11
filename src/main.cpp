#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    Emulator emulator;

    emulator.Reset();

    if (!emulator.LoadROM("roms/store.rom"))
    {
        printf("Unable to load ROM\n");

        return 1;
    }

    //-------------------------------------------------
    // Préparation
    //-------------------------------------------------

    emulator.GetMemory().Write8(0x1000, 0);
    emulator.GetCPU().GetRegister(0x00) = 42;

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 STORE Validation\n");
    printf("========================================\n");
    printf("\n");

    printf(
        "Memory[1000h] before execution = %u\n",
        emulator.GetMemory().Read8(0x1000));

    printf("\n");

    emulator.Run();

    printf("\n");

    printf(
        "Memory[1000h] after execution = %u\n",
        emulator.GetMemory().Read8(0x1000));

    printf("\n");

    printf("========================================\n");
    printf("STORE ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}