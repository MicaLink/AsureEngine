#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestPOP()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    //-----------------------------------------
    // Préparation de la pile
    //-----------------------------------------

    cpu.Push8(memory, 42);

    //-----------------------------------------
    // POP B
    //-----------------------------------------

    memory.Write8(0x0000, 0x21);
    memory.Write8(0x0001, 0x01);

    cpu.Step(memory);

    //-----------------------------------------
    // Validation
    //-----------------------------------------

    assert(cpu.GetRegister(0x01) == 42);
    assert(cpu.GetSP() == 0xFFFF);
}