#pragma once

#include <Windows.h>

class Timer
{
public:
    void Initialize();
    void Update();

    float GetDeltaTime() const;
    float GetFPS() const;

private:
    LARGE_INTEGER m_Frequency{};
    LARGE_INTEGER m_LastCounter{};

    float m_DeltaTime = 0.0f;
    float m_FPS = 0.0f;
};
