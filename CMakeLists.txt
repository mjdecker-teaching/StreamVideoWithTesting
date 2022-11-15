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
                      COMMAND ./StreamingActivity
                      DEPENDS StreamingActivity)

# Test programs
set(VIDEO_SOURCE VideoTest.cpp Video.cpp)
add_executable(VideoTest ${VIDEO_SOURCE})
set(STREAM_SOURCE StreamTest.cpp Stream.cpp Video.cpp)
add_executable(StreamTest ${STREAM_SOURCE})
set(ACCOUNT_SOURCE AccountTest.cpp Account.cpp Stream.cpp Video.cpp)
add_executable(AccountTest ${ACCOUNT_SOURCE})

# Run all tests
add_custom_target(test COMMENT "Run all tests"
                       COMMAND $<TARGET_FILE:VideoTest>
                       COMMAND $<TARGET_FILE:StreamTest>
                       COMMAND $<TARGET_FILE:AccountTest>
                       DEPENDS VideoTest
                       DEPENDS StreamTest
                       DEPENDS AccountTest)

# Download external library (in single include file) catch.hpp
# Note: If Download does not work, download manually
file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.7/catch.hpp
              ${CMAKE_SOURCE_DIR}/catch.hpp)
