#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/add.rom";

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

    emulator.GetCPU().GetRegister(0x00) = 10; // A

    emulator.GetCPU().GetRegister(0x01) = 32; // B

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 ADD Validation\n");
    printf("========================================\n");
    printf("\n");

    printf(
        "Register A before execution = %u\n",
        emulator.GetCPU().GetRegister(0x00));

    printf(
        "Register B before execution = %u\n",
        emulator.GetCPU().GetRegister(0x01));

    printf(
        "FLAGS before execution = %02X\n",
        emulator.GetCPU().GetFlags());

    printf("\n");

    emulator.Run();

    printf("\n");

    printf(
        "Register A after execution = %u\n",
        emulator.GetCPU().GetRegister(0x00));

    printf(
        "Register B after execution = %u\n",
        emulator.GetCPU().GetRegister(0x01));

    printf(
        "FLAGS after execution = %02X\n",
        emulator.GetCPU().GetFlags());

    printf("\n");

    printf("========================================\n");
    printf("ADD ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}