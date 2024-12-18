#include <gtest/gtest.h>
#include "../solution/solution.hpp"
#include "climits"

TEST(Lab1, Zero) {
  std::size_t result = Solution(0u, 0u);
  ASSERT_EQ(result, 0u);
}

TEST(Lab1, CheckMaxNumber) {
  std::size_t result = Solution(SIZE_MAX, SIZE_MAX);
  ASSERT_EQ(result, 64u);
}

TEST(Lab1, Simple) {
  std::size_t result = Solution(1, 3);
  ASSERT_EQ(result, 4u);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
