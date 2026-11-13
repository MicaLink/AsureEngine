#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestSUB()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();
    
    cpu.GetRegister(0x00) = 50;
    cpu.GetRegister(0x01) = 8;

    memory.Write8(0x0000, 0x33);
    memory.Write8(0x0001, 0x00);
    memory.Write8(0x0002, 0x01);

    cpu.Step(memory);

    assert(cpu.GetRegister(0x00) == 42);
}