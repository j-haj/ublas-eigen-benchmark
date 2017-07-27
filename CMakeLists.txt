cmake_minimum_required(VERSION 3.5.0)
project(ublas-eigen-benchmark)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# Use C++ 14
set(CMAKE_CXX_STANDARD 14)

# Find Boost::ublas
find_package(Boost 1.61.0)

# Add include directories
include_directories(SYSTEM "${SRC_DIR}/eigen/")
include_directories(${Boost_INCLUDE_DIR})

add_definitions(-DBOOST_LOG_DYN_LINK)

set(SOURCES
  ${SRC_DIR}/main.cc)

# Create binary
add_executable(run_benchmark ${SRC_DIR}/main.cc ${SOURCES})
target_link_libraries(run_benchmark ${Boost_LIBRARIES})
