# @file CMakeLists.txt
# 
# CMake files for read experiments

cmake_minimum_required(VERSION 3.18)

# project info
project(Streaming)

# C++11 standard
set(CMAKE_CXX_STANDARD 17)

# Main program
add_executable(StreamingActivity StreamingActivity.cpp
                                 Video.cpp
                                 Stream.cpp
                                 Account.cpp)

# Run main program
add_custom_target(run COMMENT "Run main program"
                      COMMAND $<TARGET_FILE:StreamingActivity>
                      DEPENDS StreamingActivity)

# Test program dependency catch2
include(FetchContent)
FetchContent_Declare(catch2
  URL https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
  DOWNLOAD_NO_EXTRACT TRUE
)
FetchContent_MakeAvailable(catch2)
add_library(catch2 INTERFACE IMPORTED)
target_include_directories(catch2 SYSTEM INTERFACE ${catch2_SOURCE_DIR})


# Test programs
add_executable(VideoTest VideoTest.cpp Video.cpp)
target_link_libraries(VideoTest catch2)
add_executable(StreamTest StreamTest.cpp Stream.cpp Video.cpp)
target_link_libraries(StreamTest catch2)
add_executable(AccountTest AccountTest.cpp Account.cpp Stream.cpp Video.cpp)
target_link_libraries(AccountTest catch2)

# Run all tests
add_custom_target(test COMMENT "Run all tests"
                       COMMAND $<TARGET_FILE:VideoTest>
                       COMMAND $<TARGET_FILE:StreamTest>
                       COMMAND $<TARGET_FILE:AccountTest>
                       DEPENDS VideoTest
                       DEPENDS StreamTest
                       DEPENDS AccountTest)
