#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/ret.rom";

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
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 RET Validation\n");
    printf("========================================\n");
    printf("\n");

    printf(
        "SP before execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "PC before execution = %04X\n",
        emulator.GetCPU().GetPC());

    printf("\n");

    emulator.Run();

    printf("\n");

    printf(
        "SP after execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf(
        "PC after execution = %04X\n",
        emulator.GetCPU().GetPC());

    printf("\n");

    printf(
        "Stack[FFFEh] = %02X\n",
        emulator.GetMemory().Read8(0xFFFE));

    printf(
        "Stack[FFFFh] = %02X\n",
        emulator.GetMemory().Read8(0xFFFF));

    printf("\n");

    printf("========================================\n");
    printf("RET ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}