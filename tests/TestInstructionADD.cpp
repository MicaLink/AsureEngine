#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestADD()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    cpu.GetRegister(0x00) = 10;
    cpu.GetRegister(0x01) = 32;

    memory.Write8(0x0000, 0x32);
    memory.Write8(0x0001, 0x00);
    memory.Write8(0x0002, 0x01);

    cpu.Step(memory);

    assert(cpu.GetRegister(0x00) == 42);
}