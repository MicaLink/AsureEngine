#include "../src/Azure8/CPU.h"

#include <cassert>

void TestZeroFlag()
{
    CPU cpu;

    cpu.Reset();

    cpu.UpdateZeroFlag(0);

    assert(cpu.IsFlagSet(FLAG_ZERO));
}

void TestNegativeFlag()
{
    CPU cpu;

    cpu.Reset();

    cpu.UpdateNegativeFlag(0x80);

    assert(cpu.IsFlagSet(FLAG_NEGATIVE));
}

void TestCarryFlag()
{
    CPU cpu;

    cpu.Reset();

    cpu.UpdateCarryFlag(true);

    assert(cpu.IsFlagSet(FLAG_CARRY));
}

void TestOverflowFlag()
{
    CPU cpu;

    cpu.Reset();

    cpu.UpdateOverflowFlag(true);

    assert(cpu.IsFlagSet(FLAG_OVERFLOW));
}