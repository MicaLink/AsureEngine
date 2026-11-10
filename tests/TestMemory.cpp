#include "../src/Azure8/Memory.h"

#include <cassert>

void TestReadWrite8()
{
    Memory memory;
    memory.Reset();

    memory.Write8(0x1234, 0x42);
    assert(memory.Read8(0x1234) == 0x42);
}

void TestReadWrite16()
{
    Memory memory;
    memory.Reset();

    memory.Write16(0x1000, 0x1234);
    assert(memory.Read16(0x1000) == 0x1234);
}