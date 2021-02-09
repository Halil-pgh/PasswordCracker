#include <iostream>

#define WRITE_DETAILS 1

#include "Cracker.hpp"
#include "Timer.hpp"

int main()
{
    char repait;
    do
    {
        std::cout << "What is your password: ";
        std::string pass;
        std::cin >> pass;
        Password password(pass);

        Timer timer("Password cracking");
        Cracker cracker;
        cracker.Crack(password);
        timer.End();

        std::cout << "Do you want to crack another password [Y/n]: ";
        std::cin >> repait;
    } while (repait == 'y' || repait == 'Y');
}
