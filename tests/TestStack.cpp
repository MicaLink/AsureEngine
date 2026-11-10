#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestPushPop8()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    cpu.Push8(memory, 0xAA);
    assert(cpu.Pop8(memory) == 0xAA);
}

void TestPushPop16()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    cpu.Push16(memory, 0x1234);
    assert(cpu.Pop16(memory) == 0x1234);
}