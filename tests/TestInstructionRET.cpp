#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestRET()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    //-----------------------------------------
    // Préparation
    //-----------------------------------------

    cpu.Push16(memory, 0x1234);

    //-----------------------------------------
    // RET
    //-----------------------------------------

    memory.Write8(0x0000, 0x23);
    cpu.Step(memory);

    //-----------------------------------------
    // Validation
    //-----------------------------------------

    assert(cpu.GetPC() == 0x1234);
    assert(cpu.GetSP() == 0xFFFF);
}