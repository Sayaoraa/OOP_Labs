#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "FixedBlockMemoryResource.h"

struct ComplexType {
    int a;
    double b;
    std::string c;
};

TEST(DynamicArrayTest, IntArray) {
    FixedBlockMemoryResource memory_resource(1024); // 1 KB fixed block
    DynamicArray<int> int_array(&memory_resource);

    int_array.push_back(1);
    int_array.push_back(2);
    int_array.push_back(3);

    ASSERT_EQ(int_array.begin(), int_array.end() - 3);
    ASSERT_EQ(*int_array.begin(), 1);
    ASSERT_EQ(*(int_array.begin() + 1), 2);
    ASSERT_EQ(*(int_array.begin() + 2), 3);
}

TEST(DynamicArrayTest, ComplexArray) {
    FixedBlockMemoryResource memory_resource(1024); // 1 KB fixed block
    DynamicArray<ComplexType> complex_array(&memory_resource);

    complex_array.push_back({1, 2.0, "three"});
    complex_array.push_back({4, 5.0, "six"});

    ASSERT_EQ(complex_array.begin(), complex_array.end() - 2);
    ASSERT_EQ(complex_array.begin()->a, 1);
    ASSERT_EQ(complex_array.begin()->b, 2.0);
    ASSERT_EQ(complex_array.begin()->c, "three");
    ASSERT_EQ((complex_array.begin() + 1)->a, 4);
    ASSERT_EQ((complex_array.begin() + 1)->b, 5.0);
    ASSERT_EQ((complex_array.begin() + 1)->c, "six");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
