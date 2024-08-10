cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

set(PARALLEL_EXECUTOR_PROJECT_NAME parallel_executor)
set(CMAKE_CXX_STANDARD 14)

set(HEADERS 
    DataEvent.h
    Device.h
    DeviceA.h
    DeviceB.h
    DeviceEvent.h
    Event.h
    EventQueue.h
    StartedEvent.h
    WorkDoneEvent.h
    Parser.h
)

set(SOURCES
    DeviceA.cpp
    DeviceB.cpp
    events.cpp
    EventQueue.cpp
    Parser.cpp
)

add_library(${PARALLEL_EXECUTOR_PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)