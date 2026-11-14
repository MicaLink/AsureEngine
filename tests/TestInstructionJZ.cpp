#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

//-----------------------------------------------------
// TestJZ
//-----------------------------------------------------

void TestJZ()
{
    //-------------------------------------------------
    // Jump Taken
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.SetFlag(FLAG_ZERO);
    
        memory.Write8(0x0000, 0x42);
        memory.Write8(0x0001, 0x34);
        memory.Write8(0x0002, 0x12);

        cpu.Step(memory);

        assert(cpu.GetPC() == 0x1234);
    }
    
    //-------------------------------------------------
    // Jump Not Taken
    //-------------------------------------------------

    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.ClearFlag(FLAG_ZERO);
    
        memory.Write8(0x0000, 0x42);
        memory.Write8(0x0001, 0x34);
        memory.Write8(0x0002, 0x12);

        cpu.Step(memory);

        assert(cpu.GetPC() == 0x0003);
    }
}