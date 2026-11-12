#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestPUSH()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    cpu.GetRegister(0x00) = 42;

    memory.Write8(0x0000, 0x20);
    memory.Write8(0x0001, 0x00);

    cpu.Step(memory);

    assert(memory.Read8(0xFFFF) == 42);
    assert(cpu.GetSP() == 0xFFFE);
}