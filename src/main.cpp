#include "Azure8/Emulator.h"

#include <cstdio>
#include <stdlib.h>

int main()
{
    Emulator emulator;

    if (!emulator.LoadROM("../roms/test.rom"))
    {
        printf("Unable to load ROM\n");
        system("pause");
        
        return -1;
    }
    emulator.Run();

    system("pause");
    
    return 0;
}