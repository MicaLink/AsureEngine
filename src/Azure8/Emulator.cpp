#include "Emulator.h"

#include <cstdio>

bool Emulator::LoadROM(const char* fileName)
{
    FILE* file = nullptr;

    fopen_s(&file, fileName, "rb");

    if (!file)
        return false;
    
    u16 address = 0;

    while (!feof(file))
    {
        const int byte = fgetc(file);

        if (byte == EOF)
            break;

        m_Memory.Write8(address++, static_cast<u8>(byte));
    }
    
    fclose(file);

    printf("ROM Loaded\n");

    return true;
}

void Emulator::Reset()
{
    m_Memory.Reset();
    m_CPU.Reset();
}

void Emulator::Run()
{
    while (!m_CPU.IsHalted())
    {
        m_CPU.Step(m_Memory);
    }
    printf("Execution Completed\n");
}