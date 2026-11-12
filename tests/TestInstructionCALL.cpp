#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestCALL()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    memory.Write8(0x0000, 0x22);
    memory.Write8(0x0001, 0x00);
    memory.Write8(0x0002, 0x10);

    cpu.Step(memory);

    assert(cpu.GetSP() == 0xFFFD);
    assert(memory.Read16(0xFFFE) == 0x0003);
    assert(cpu.GetPC() == 0x1000);
}