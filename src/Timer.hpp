#pragma once

#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer(const std::string &name)
        : m_Name(name)
    {
        m_Start = m_Timer.now();
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
        
        m_End = m_Timer.now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(m_End - m_Start);
        std::cout << m_Name << " tooks: " << deltaTime.count() << "ms\n";
        m_IsEnd = true;        
    }

private:
    bool m_IsEnd = false;
    std::string m_Name;

    std::chrono::high_resolution_clock m_Timer;
    std::chrono::_V2::system_clock::time_point m_Start;
    std::chrono::_V2::system_clock::time_point m_End;
};