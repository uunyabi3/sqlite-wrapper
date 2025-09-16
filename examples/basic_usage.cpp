#include "database.h"
#include <iostream>

int main() {
    try
    {
        Database db("test.db");
        db.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT)");
        db.execute("INSERT INTO users (name) VALUES ('nyabi')");  
        
        std::cout << "=== All users ===" << std::endl;
        db.printAll("users");
        
    } 
    catch (const SQLiteError& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}