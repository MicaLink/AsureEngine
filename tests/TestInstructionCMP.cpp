#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

//-----------------------------------------------------
// TestCMP
//-----------------------------------------------------

void TestCMP()
{
    //-------------------------------------------------
    // CMP Equal
    //-------------------------------------------------

    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 42;
        cpu.GetRegister(0x01) = 42;

        memory.Write8(0x0000, 0x40);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.IsFlagSet(FLAG_ZERO));
        assert(!cpu.IsFlagSet(FLAG_NEGATIVE));
        assert(!cpu.IsFlagSet(FLAG_CARRY));

        assert(cpu.GetRegister(0x00) == 42);
        assert(cpu.GetRegister(0x01) == 42);
    }

    //-------------------------------------------------
    // CMP Greater
    //-------------------------------------------------

    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 42;
        cpu.GetRegister(0x01) = 10;

        memory.Write8(0x0000, 0x40);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(!cpu.IsFlagSet(FLAG_ZERO));
        assert(!cpu.IsFlagSet(FLAG_NEGATIVE));
        assert(!cpu.IsFlagSet(FLAG_CARRY));

        assert(cpu.GetRegister(0x00) == 42);
        assert(cpu.GetRegister(0x01) == 10);
    }

    //-------------------------------------------------
    // CMP Less
    //-------------------------------------------------

    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 10;
        cpu.GetRegister(0x01) = 42;

        memory.Write8(0x0000, 0x40);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(!cpu.IsFlagSet(FLAG_ZERO));
        assert(cpu.IsFlagSet(FLAG_NEGATIVE));
        assert(cpu.IsFlagSet(FLAG_CARRY));

        assert(cpu.GetRegister(0x00) == 10);
        assert(cpu.GetRegister(0x01) == 42);
    }

}