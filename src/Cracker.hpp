#pragma once

#if WRITE_DETAILS
    #include <iostream>
#endif

#include "Password.hpp"
#include "Guesser.hpp"

class Cracker
{
public:    
    void Crack(const Password& password, Guesser* guesser)
    {
        int tries = 0;
        while (true)
        {
            guesser->GuessNext();

            #if WRITE_DETAILS
                std::cout << "Trying: " << guesser->GetMessage() << "\n";
            #endif

            if (password.IsEqual(guesser->GetMessage()))
                break;

            tries++;
        }

        #if WRITE_DETAILS
            std::cout << "Password cracked succesfully!\n";
            std::cout << "Password: " << guesser->GetMessage() << '\n';
            std::cout << "Password length: " << guesser->GetMessage().length() << '\n';
            std::cout << "Tries count for cracking password: " << tries << '\n';
        #endif
    }
};