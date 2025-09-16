#pragma once

#include <stdexcept>
#include <string>

class SQLiteError : public std::runtime_error
{
public:
    SQLiteError(const std::string& msg) : std::runtime_error(msg) {}
};

