#pragma once

#include <string>

class Cursor
{
public:
    Cursor() : m_Message()
    {
        m_Message.push_back(m_StartingDecimal);
    }

    void WriteNext()
    {
        m_Decimal++;
        m_Message[m_Position] = m_Decimal;
        while (m_Decimal > m_EndingDecimal)
        {
            m_Message[m_Position] = m_StartingDecimal;
            DecreasePosition();
            m_Decimal++;
            m_Message[m_Position] = m_Decimal;
        }
        ResetPosition();
    }

    void ResetPosition()
    {
        m_Position = m_Message.length() - 1;
        m_Decimal = m_Message[m_Position];
    }

    void IncreasePosition()
    {
        if (m_Position == m_Message.length() - 1)
            return;
        m_Position++;
        m_Decimal = m_Message[m_Position];
    }

    void DecreasePosition()
    {
        m_Position--;
        if (m_Position < 0)
        {
            m_Message += (m_StartingDecimal - 1);
            m_Position = m_Message.length() - 1;
        }
        m_Decimal = m_Message[m_Position];
    }

    inline int GetPosition() const { return m_Position; }
    inline const std::string& GetMessage() const { return m_Message; }

private:
    std::string m_Message;

    int m_Position = 0;
    int m_StartingDecimal = 32;
    int m_Decimal = m_StartingDecimal;
    int m_EndingDecimal = 125;
};