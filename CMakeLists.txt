cmake_minimum_required(VERSION 3.17)

project(Re)

set(CMAKE_CXX_STANDARD 20)

find_package(jsoncpp CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

add_executable(Re main.cpp State.cpp State.h NFAGraph.cpp NFAGraph.h)
target_link_libraries(Re PRIVATE jsoncpp_lib GTest::gtest GTest::gtest_main glog::glog)
