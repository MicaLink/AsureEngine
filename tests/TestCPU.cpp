#include "../src/Azure8/CPU.h"

#include <cassert>

void TestReset()
{
    CPU cpu;

    cpu.Reset();

    assert(cpu.GetSP() == 0xFFFF);

    assert(cpu.GetFlags() == 0);

    assert(cpu.IsHalted() == false);

    assert(cpu.HasStackOverflow() == false);

    assert(cpu.HasStackUnderflow() == false);
}