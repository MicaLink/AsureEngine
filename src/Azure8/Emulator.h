#pragma once

#include "CPU.h"
#include "Memory.h"

//-----------------------------------------------------
// Emulator
//-----------------------------------------------------

class Emulator
{
public:
    bool LoadROM(const char* fillName);

    void Reset();
    void Run();

    Memory& GetMemory();
private:
    CPU m_CPU;
    Memory m_Memory;
};