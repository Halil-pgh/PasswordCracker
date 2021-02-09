#include <iostream>

#include "Cracker.hpp"
#include "Timer.hpp"

int main()
{
    std::cout << "What is your password: ";
    std::string pass;
    std::cin >> pass;
    Password password(pass);

    Timer timer("Password cracking");
    Cracker cracker;
    cracker.WriteToConsole(false);
    cracker.Crack(password);
    timer.End();
}
