#include <gtest/gtest.h>
#include "functions.h"

TEST(CountOnesTest, Basic) {
    EXPECT_EQ(countOnesInRange(2, 7), 11);
    EXPECT_EQ(countOnesInRange(0, 0), 0);
    EXPECT_EQ(countOnesInRange(1, 1), 1);
    EXPECT_EQ(countOnesInRange(7, 7), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
