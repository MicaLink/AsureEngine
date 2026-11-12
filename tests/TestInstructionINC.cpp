#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestINC()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    cpu.GetRegister(0x00) = 41;

    memory.Write8(0x0000, 0x30);
    memory.Write8(0x0001, 0x00);

    cpu.Step(memory);

    assert(cpu.GetRegister(0x00) == 42);
}