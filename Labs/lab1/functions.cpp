#include "functions.h"

int countOnesInRange(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; ++i) {
        int num = i;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
    }
    return count;
}
