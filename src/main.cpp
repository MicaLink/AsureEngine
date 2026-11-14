#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/jmp.rom";

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

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 JMP Validation\n");
    printf("========================================\n");
    printf("\n");

    printf(
        "PC before execution = %04X\n",
        emulator.GetCPU().GetPC());

    printf(
        "SP before execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "FLAGS before execution = %02X\n",
        emulator.GetCPU().GetFlags());

    printf("\n");

    emulator.Run();

    printf("\n");

    printf(
        "PC after execution = %04X\n",
        emulator.GetCPU().GetPC());

    printf(
        "SP after execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "FLAGS after execution = %02X\n",
        emulator.GetCPU().GetFlags());

    printf("\n");

    printf("========================================\n");
    printf("JMP ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}