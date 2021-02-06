cmake_minimum_required(VERSION 3.16)

project(Re)

set(CMAKE_CXX_STANDARD 20)

find_package(glog CONFIG REQUIRED)


FILE (GLOB ALL_FILE src/*)

FOREACH (FILE ${ALL_FILE})
    MESSAGE(STATUS ${FILE})
ENDFOREACH ()

add_executable(Re ${ALL_FILE})
target_link_libraries(Re PRIVATE glog::glog)

#
#add_test(Test Re)
#enable_testing()