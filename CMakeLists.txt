cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

project(sync_threads)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Boost COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(${CMAKE_SOURCE_DIR}/src/parallel_executor)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/parallel_executor/main.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} parallel_executor)

enable_testing()
add_subdirectory(test)
