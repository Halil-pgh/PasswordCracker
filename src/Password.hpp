#pragma once

#include <string>

class Password
{
public:
    Password(const std::string& pass) : m_Pass(pass) {}
    bool IsEqual(const std::string& pass) const { return m_Pass == pass; }
    const std::string& GetPassword() const { return m_Pass; }

private:
    std::string m_Pass;
};
