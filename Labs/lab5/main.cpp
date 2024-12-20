#include "DynamicArray.h"
#include "FixedBlockMemoryResource.h"
#include <iostream>
#include <string>

struct ComplexType {
    int a;
    double b;
    std::string c;
};

int main() {
    FixedBlockMemoryResource memory_resource(1024); // 1 KB fixed block
    DynamicArray<int> int_array(&memory_resource);
    DynamicArray<ComplexType> complex_array(&memory_resource);

    int_array.push_back(1);
    int_array.push_back(2);
    int_array.push_back(3);

    complex_array.push_back({1, 2.0, "three"});
    complex_array.push_back({4, 5.0, "six"});

    std::cout << "Int Array: ";
    for (int value : int_array) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Array: ";
    for (const auto& value : complex_array) {
        std::cout << "{" << value.a << ", " << value.b << ", " << value.c << "} ";
    }
    std::cout << std::endl;

    return 0;
}
