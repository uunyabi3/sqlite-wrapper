cmake_minimum_required(VERSION 3.20)
project(SQLiteWrapper)

set(CMAKE_CXX_STANDARD 17)

add_library(sqlite3 external/sqlite3.c)
target_include_directories(sqlite3 PUBLIC external/)

add_library(sqlite_wrapper
    src/database.cpp
    src/statement.cpp
    src/result_set.cpp
    src/exceptions.cpp
)

target_include_directories(sqlite_wrapper PUBLIC include/)
target_link_libraries(sqlite_wrapper sqlite3)

add_executable(example examples/basic_usage.cpp)
target_link_libraries(example sqlite_wrapper)