cmake_minimum_required(VERSION 3.26)

project(lynxdb)
set(CMAKE_CXX_STANDARD 20)

add_library(lynxdb SHARED)
target_sources(
        lynxdb
        PRIVATE
        "src/DB.cc"
        "src/Bytes.h"
        "src/Bytes.cc"
        PUBLIC
        "src/DB.h"
)

# lynxdb test
add_subdirectory("dependency/googletest")

add_executable(lynxdb_test)
target_sources(
        lynxdb_test
        PRIVATE
        "src/DB_test.cc"
)
target_link_libraries(lynxdb_test lynxdb GTest::gtest_main)
