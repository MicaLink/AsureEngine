#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestSTORE()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();
    memory.Reset();

    //-------------------------------------------------
    // Préparation
    //-------------------------------------------------

    cpu.GetRegister(0x00) = 42;

    //-------------------------------------------------
    // STORE A, 1000h
    //-------------------------------------------------

    memory.Write8(0x0000, 0x12);
    memory.Write8(0x0001, 0x00);
    memory.Write8(0x0002, 0x00);
    memory.Write8(0x0003, 0x10);

    //-------------------------------------------------
    // Exécution
    //-------------------------------------------------

    cpu.Step(memory);

    //-------------------------------------------------
    // Validation
    //-------------------------------------------------

    assert(memory.Read8(0x1000) == 42);
}