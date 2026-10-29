#include "Timer.h"

void Timer::Initialize() {    
    QueryPerformanceFrequency(&m_Frequency);
    QueryPerformanceCounter(&m_LastCounter);

    m_DeltaTime = 0.0f;
    m_FPS = 0.0f;
}

void Timer::Update() {
    LARGE_INTEGER currentCounter;
    
    QueryPerformanceCounter(&currentCounter);

    m_DeltaTime = static_cast<float>(currentCounter.QuadPart - m_LastCounter.QuadPart) / static_cast<float>(m_Frequency.QuadPart);

    m_LastCounter = currentCounter;

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