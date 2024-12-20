cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

# Добавляем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# Убедимся, что Google Test скачивается и настраивается до того, как мы попытаемся использовать его
FetchContent_MakeAvailable(googletest)

# Добавляем исполняемые файлы
add_executable(Lab1 main.cpp functions.cpp)
add_executable(RunTests unit.cpp functions.cpp)

# Связываем Google Test с тестами
target_link_libraries(RunTests gtest gtest_main)
