#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/pop.rom";

    //-------------------------------------------------
    // Init
    //-------------------------------------------------

    Emulator emulator;

    emulator.Reset();

    //-------------------------------------------------
    // Load ROM
    //-------------------------------------------------

    if (!emulator.LoadROM(ROM_PATH))
    {
        printf("FAILED TO LOAD ROM\n");

        return 1;
    }

    //-------------------------------------------------
    // Initialisation
    //-------------------------------------------------

    emulator.GetCPU().Push8(emulator.GetMemory(), 42);

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 POP Validation\n");
    printf("========================================\n");
    printf("\n");

    printf(
        "SP before execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "Memory[FFFFh] = %u\n",
        emulator.GetMemory().Read8(0xFFFF));

    printf("\n");

    emulator.Run();

    printf("\n");

    printf(
        "SP after execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "Register B = %u\n",
        emulator.GetCPU().GetRegister(0x01));

    printf("\n");

    printf("========================================\n");
    printf("POP ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}