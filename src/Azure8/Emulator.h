#pragma once

#include "CPU.h"
#include "Memory.h"

class Emulator
{
public:
    bool LoadROM(const char* fillName);

    void Reset();
    void Run();
private:
    CPU m_CPU;
    Memory m_Memory;
};