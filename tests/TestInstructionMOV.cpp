#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestMOV()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    memory.Write8(0x0000, 0x10);
    memory.Write8(0x0001, 0x00);
    memory.Write8(0x0002, 0x01);

    memory.Write8(0x0003, 0xFF);

    cpu.GetRegister(0x01) = 42;

    cpu.Step(memory);

    assert(cpu.GetRegister(0x00) == 42);
}