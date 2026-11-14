#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestJMP()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    memory.Write8(0x0000, 0x41);
    memory.Write8(0x0001, 0x34);
    memory.Write8(0x0002, 0x12);

    cpu.Step(memory);

    assert(cpu.GetPC() == 0x1234);
}