enable_testing()

add_executable(lab1_testing tests/unit.cpp)
target_link_libraries(lab1_testing PRIVATE gtest)
target_compile_options(lab1_testing PRIVATE -fsanitize=address,undefined)

include(GoogleTest)
gtest_discover_tests(lab1_testing)
