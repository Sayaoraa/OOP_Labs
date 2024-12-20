#include <iostream>
#include "functions.h"

int main() {
    int a, b;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Number of 1s: " << countOnesInRange(a, b) << std::endl;
    return 0;
}
