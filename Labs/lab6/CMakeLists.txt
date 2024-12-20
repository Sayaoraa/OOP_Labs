cmake_minimum_required(VERSION 3.10)
project(BalagurFate3)

set(CMAKE_CXX_STANDARD 17)

# Добавляем библиотеку gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавляем исходные файлы
set(SOURCES
    src/Bandit.cpp
    src/Knight.cpp
    src/Elf.cpp
    src/NPCFactory.cpp
    src/BattleVisitor.cpp
    src/FileObserver.cpp
    src/ConsoleObserver.cpp
)

# Добавляем заголовочные файлы
set(HEADERS
    src/NPC.h
    src/Visitor.h
    src/Observer.h
    src/Bandit.h
    src/Knight.h
    src/Elf.h
    src/NPCFactory.h
    src/BattleVisitor.h
    src/FileObserver.h
    src/ConsoleObserver.h
)

# Добавляем тесты
set(TEST_SOURCES
    tests/test_main.cpp
)

# Указываем директории для поиска заголовочных файлов
include_directories(src)

# Создаем исполняемый файл
add_executable(BalagurFate3 src/main.cpp ${SOURCES} ${HEADERS})

# Создаем тесты
add_executable(runTests ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Включаем тесты в проект
enable_testing()
add_test(NAME runTests COMMAND runTests)
