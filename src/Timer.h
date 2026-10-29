#pragma once

class Timer
{
public:
    void Initialize();
    void Update();

    float GetDeltaTime() const;
    float GetFPS() const;

private:
    long long m_Frequency = 0;
    long long m_LastCounter = 0;

    float m_DeltaTime = 0.0f;
    float m_FPS = 0.0f;
};
