#pragma once

#include <iostream>

#include "Password.hpp"
#include "Cursor.hpp"

class Cracker
{
public:    
    void Crack(const Password& password)
    {
        int tries = 0;
        Cursor cursor;
        while (true)
        {
            cursor.WriteNext();

            #if WRITE_DETAILS
                std::cout << "Trying: " << cursor.GetMessage() << "\n";
            #endif

            if (password.IsEqual(cursor.GetMessage()))
                break;
            
            tries++;
        }

        #if WRITE_DETAILS
            std::cout << "Password cracked succesfully!\n";
            std::cout << "Password: " << cursor.GetMessage() << '\n';
            std::cout << "Password length: " << cursor.GetMessage().length() << '\n';
            std::cout << "Tries count for cracking password: " << tries << '\n';
        #endif
    }
};