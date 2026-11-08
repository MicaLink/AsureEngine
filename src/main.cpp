#include "Azure8/Emulator.h"
#include "Azure8/CPU.h"
#include "Azure8/Memory.h"

#include <cstdio>

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    Memory memory;
    CPU cpu;

    memory.Reset();
    cpu.Reset();

    cpu.SetFlag(FLAG_ZERO);
    cpu.SetFlag(FLAG_CARRY);

    printf("FLAGS = %02X\n", cpu.GetFlags());
    printf("ZERO  = %d\n", cpu.IsFlagSet(FLAG_ZERO));
    printf("CARRY = %d\n", cpu.IsFlagSet(FLAG_CARRY));

    cpu.ClearFlag(FLAG_ZERO);

    printf("FLAGS = %02X\n", cpu.GetFlags());

    return 0;
} 