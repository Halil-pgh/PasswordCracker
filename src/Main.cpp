#include <iostream>

#define WRITE_DETAILS 1

#include "Cracker.hpp"
#include "Timer.hpp"
#include "CursorGuesser.hpp"

int main()
{
    char repeat;
    do
    {
        std::cout << "What is your password: ";
        std::string pass;
        std::cin >> pass;
        Password password(pass);

        Timer timer("Password cracking");
        Guesser* guesser = new CursorGuesser();
        Cracker cracker;
        cracker.Crack(password, guesser);
        delete guesser;
        timer.End();

        std::cout << "Do you want to crack another password [Y/n]: ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}
