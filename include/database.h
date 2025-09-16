#pragma once

#include <string>  
#include <sqlite3.h>
#include <iostream>
#include "exceptions.h"

class Database
{
private:
    sqlite3* db;

    void bindParameter(sqlite3_stmt* stmt, int index, int value);
    void bindParameter(sqlite3_stmt* stmt, int index, const std::string& value);
    void bindParameter(sqlite3_stmt* stmt, int index, double value);

public:
    Database(const std::string& path);
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    void printAll(const std::string& tableName);

    template<typename... Args>
    void execute(const std::string& sql, Args... args);
};

