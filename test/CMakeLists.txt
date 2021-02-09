cmake_minimum_required(VERSION 3.16)

project(ReTest)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)


include_directories(../src)
MESSAGE(${CMAKE_CURRENT_SOURCE_DIR})

set(
        SOURCE_FILE
        ../src/Utils.h
        ../src/Utils.cpp
        ../src/Token.h
        ../src/NFAGraph.h
        ../src/NFAGraph.cpp
        ../src/NFAState.cpp
        ../src/NFAState.h
        ../src/DFA.cpp
        ../src/DFA.h
        ../src/DFAState.cpp
        ../src/DFAState.h
        ../src/MinimizeDFA.cpp
        ../src/MinimizeDFA.h
        ../src/Define.h
        ../src/TableDrivenScanner.cpp
        ../src/TableDrivenScanner.h
        ../src/Lexeme.h
        ../src/Lexeme.cpp
        TestKeyWord.cpp
        ../src/Lexicon.cpp ../src/Lexicon.h TestLexicon.cpp)


add_executable(ReTest UniTest.h UniTest.cpp ${SOURCE_FILE})
target_link_libraries(ReTest PUBLIC GTest::gtest GTest::gtest_main glog::glog)

