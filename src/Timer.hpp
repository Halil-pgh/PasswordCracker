#pragma once

#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer(const std::string &name)
        : m_Name(name)
    {
        m_Start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        if (m_IsEnd == false)
            End();
    }

    void End()
    {
        if (m_IsEnd)
            return;
        
        m_End = std::chrono::steady_clock::now();
        m_Duration = m_End - m_Start;
        float ms = m_Duration.count() * 1000.0f;
        std::cout << m_Name << " tooks: " << ms << "ms\n";
        m_IsEnd = true;
    }

private:
    bool m_IsEnd = false;
    std::string m_Name;

    std::chrono::time_point<std::chrono::steady_clock> m_Start, m_End;
    std::chrono::duration<float> m_Duration;
};