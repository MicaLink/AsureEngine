#include "Azure8/Emulator.h"

#include <cstdio>

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    Emulator emulator;

    if (!emulator.LoadROM("rome/test.rom"))
    {
        printf("Unable to load ROM\n");
        getchar();
        return -1;
    }

    emulator.Run();

    getchar();
    
    return 0;
}