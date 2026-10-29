#include "Timer.h"

#include <Windows.h>

void Timer::Initialize() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER counter;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);

    m_Frequency = frequency.QuadPart;
    m_LastCounter = counter.QuadPart;
}

void Timer::Update() {
    LARGE_INTEGER currentCounter;
    
    QueryPerformanceCounter(&currentCounter);

    m_DeltaTime = static_cast<float>(currentCounter.QuadPart - m_LastCounter) / static_cast<float>(m_Frequency);

    m_LastCounter = currentCounter.QuadPart;

    if (m_DeltaTime > 0.0f) {
        m_FPS = 1.0f / m_DeltaTime;
    }
    
}

float Timer::GetDeltaTime() const {
    return m_DeltaTime;
}

float Timer::GetFPS() const {
    return m_FPS;
}