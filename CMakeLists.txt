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
        "src/MemTable.h"
        "src/MemTable.cc"
        "src/SkipList.h"
        "src/SkipList.cc"
        "src/SSTable.h"
        "src/SSTable.cc"
        "src/BloomFilter.h"
        "src/BloomFilter.cc"
        "src/Level.h"
        "src/Level.cc"
        "src/LevelTree.h"
        "src/LevelTree.cc"
        "src/DeletedException.h"
        PUBLIC
        "src/DB.h"
)

# lynxdb test
add_subdirectory("dependency/googletest")

set(
        TESTS
        "DB_test"
        "Bytes_test"
        "MemTable_test"
        "SkipList_test"
        "SSTable_test"
        "Level_test"
)

function(GenerateTest NAME)
    add_executable(${NAME})
    target_sources(
            ${NAME}
            PRIVATE
            "src/${NAME}.cc"
    )
    target_link_libraries(${NAME} lynxdb GTest::gtest_main)
endfunction(GenerateTest)

foreach (TEST ${TESTS})
    message(STATUS "Generate Test: ${TEST}")
    GenerateTest(${TEST})
endforeach ()