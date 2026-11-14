#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/jnz.rom";

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

    emulator.GetCPU().ClearFlag(FLAG_ZERO);

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 JNZ Validation\n");
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

    printf("ZERO     = %s\n",
        (emulator.GetCPU().GetFlags() & FLAG_ZERO)
            ? "SET"
            : "CLEAR");

    printf("CARRY    = %s\n",
        (emulator.GetCPU().GetFlags() & FLAG_CARRY)
            ? "SET"
            : "CLEAR");

    printf("NEGATIVE = %s\n",
        (emulator.GetCPU().GetFlags() & FLAG_NEGATIVE)
            ? "SET"
            : "CLEAR");

    printf("OVERFLOW = %s\n",
        (emulator.GetCPU().GetFlags() & FLAG_OVERFLOW)
            ? "SET"
            : "CLEAR");

    printf("\n");

    printf("========================================\n");
    printf("JNZ ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}