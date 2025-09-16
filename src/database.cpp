#include "database.h"

Database::Database(const std::string& path)
{
    int result = sqlite3_open(path.c_str(), &db);
    if (result != SQLITE_OK)
    {
        std::string error = sqlite3_errmsg(db);
        sqlite3_close(db);
        throw SQLiteError("Failed to open database: " + error);
    }
}

Database::~Database()
{
    if (db)
    {
        sqlite3_close(db);
    }
}

void Database::execute(const std::string& sql) 
{
    char* error_msg = nullptr;
    int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_msg);
    

    if (result != SQLITE_OK)
    {
        std::string error = error_msg;
        sqlite3_free(error_msg);
        throw SQLiteError("SQL execution failed: " + error);
    }
}

void Database::printAll(const std::string& tableName)
{
    std::string sql = "SELECT * FROM " + tableName;

    int result = sqlite3_exec(db, sql.c_str(),
        [](void*, int argc, char** argv, char** colNames) -> int 
    {
        for (int i = 0; i < argc; ++i) 
        {
            std::cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << " ";
        }
        std::cout << std::endl;

        return 0;
    }, nullptr, nullptr);

    if (result != SQLITE_OK)
    {
        throw SQLiteError("SELECT failed");
    }
}