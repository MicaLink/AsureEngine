#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/invalide.rom";

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

    printf("\nROM LOADED : %s\n\n", ROM_PATH);

    //-------------------------------------------------
    // Debug
    //-------------------------------------------------

    emulator.Run();

    printf("\nEXECUTION COMPLETED\n");

    return 0;
}