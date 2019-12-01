#pragma once
#include <iostream>
#include <string>

class Logger
{
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& Instance()
    {
        static Logger instance;
        return instance;
    }

    void Write(const std::string& message)
    {
        os << message << std::endl;
    }

private:
    Logger() : os(std::cout) {}
    std::ostream& os;
};