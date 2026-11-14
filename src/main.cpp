#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/memory16.rom";

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
    // Préparation mémoire
    //-------------------------------------------------

    emulator.GetMemory().Write8(0x1234, 0x42);

    //-------------------------------------------------
    // Affichage avant exécution
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 Memory16 Validation\n");
    printf("========================================\n");
    printf("\n");

    printf("Memory[1234] before = %02X\n",
        emulator.GetMemory().Read8(0x1234));

    printf("Memory[5678] before = %02X\n",
        emulator.GetMemory().Read8(0x5678));

    printf("\n");

    //-------------------------------------------------
    // Exécution
    //-------------------------------------------------

    emulator.Run();

    //-------------------------------------------------
    // Résultats
    //-------------------------------------------------

    printf("\n");

    printf("Memory[1234] after  = %02X\n",
        emulator.GetMemory().Read8(0x1234));

    printf("Memory[5678] after  = %02X\n",
        emulator.GetMemory().Read8(0x5678));

    printf("\n");

    printf("========================================\n");
    printf("Memory16 ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}