cmake_minimum_required(VERSION 3.17)

project(ReTest)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

#FILE (GLOB ALL_SOURCE_FILE ../src/*.cpp)
#FILE (GLOB ALL_HEADER_FILE ../src/*.h)

#FILE(GLOB ALL_TEST_SOURCE_FILE ./*.cpp)
#FILE(GLOB ALL_TEST_HEADER_FILE ./*.h)
#
#aux_source_directory(../src SOURCE_FILE)

#FOREACH (FILE ${SOURCE_FILE})
#    MESSAGE(STATUS ${FILE})
#ENDFOREACH ()

add_executable(ReTest ../src/Utils.h ../src/Utils.cpp UniTest.h UniTest.cpp)
target_link_libraries(ReTest PUBLIC GTest::gtest GTest::gtest_main glog::glog)

