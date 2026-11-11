#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestLOAD()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    memory.Write8(0x1000, 42);

    memory.Write8(0x0000, 0x11); // LOAD
    memory.Write8(0x0001, 0x00); // A
    memory.Write8(0x0002, 0x00); // Low
    memory.Write8(0x0003, 0x10); // High

    cpu.Step(memory);

    assert(cpu.GetRegister(0x00) == 42);
}