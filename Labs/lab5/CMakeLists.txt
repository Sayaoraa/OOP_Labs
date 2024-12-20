cmake_minimum_required(VERSION 3.10)
project(Lab05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Найти Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Lab5 unit.cpp DynamicArray.h FixedBlockMemoryResource.h FixedBlockMemoryResource.cpp)

# Линковать с Google Test
target_link_libraries(Lab5 ${GTEST_LIBRARIES} pthread)

add_executable(main main.cpp DynamicArray.h FixedBlockMemoryResource.h FixedBlockMemoryResource.cpp)
