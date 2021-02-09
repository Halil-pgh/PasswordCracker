#pragma once

#include <string>

class Guesser
{
public:
    virtual void GuessNext() = 0;
    virtual const std::string& GetMessage() const = 0;
};