#pragma once

#include "Password.hpp"
#include "Cursor.hpp"

class Cracker
{
public:
    void WriteToConsole(bool write) { m_WriteToConsole = write; }
    
    void Crack(const Password& password)
    {
        Cursor cursor;
        while (true)
        {
            cursor.WriteNext();

            if (m_WriteToConsole)
                std::cout << cursor.GetMessage() << "\n";

            if (password.IsEqual(cursor.GetMessage()))
                break;
        }
        std::cout << "Password cracked succesfully!\n";
        std::cout << "Password: " << cursor.GetMessage() << '\n';
        std::cout << "Password length: " << cursor.GetMessage().length() << '\n';
    }

private:
    bool m_WriteToConsole = false;
};