#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/push.rom";

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

    emulator.GetCPU().GetRegister(0x00) = 42;

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 PUSH Validation\n");
    printf("========================================\n");
    printf("\n");

    printf("Register A = %u\n",
           emulator.GetCPU().GetRegister(0x00));

    printf("\n");

    printf("SP before execution = %04X\n",
           emulator.GetCPU().GetSP());

    printf("\n");

    emulator.Run();

    printf("\n");

    printf("SP after execution = %04X\n",
           emulator.GetCPU().GetSP());

    printf("\n");

    printf("Memory[FFFFh] = %u\n",
           emulator.GetMemory().Read8(0xFFFF));

    printf("\n");

    printf("========================================\n");
    printf("PUSH ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}