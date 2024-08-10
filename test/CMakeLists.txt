cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

set(TEST_PROJECT_NAME test_proj)
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src/parallel_executor)

set(TEST_ALL_SOURCES
    Test_Devices.cpp
    Test_EventQueue.cpp
    Test_Events.cpp
    Test_Parser.cpp
)

add_executable(${TEST_PROJECT_NAME} ${TEST_ALL_SOURCES})
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(${TEST_PROJECT_NAME} ${GTEST_LIBRARIES} gmock gmock_main)
target_link_libraries(${TEST_PROJECT_NAME} parallel_executor)

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})