#include <iostream>
#include "gtest/gtest.h"

// === Utility functions to test ===

int square(int x) {
    return x * x;
}

bool is_even(int x) {
    return x % 2 == 0;
}

// === Google Test Cases ===

TEST(SquareFunction, HandlesPositiveInput) {
    EXPECT_EQ(square(5), 25);
}

TEST(SquareFunction, HandlesZero) {
    EXPECT_EQ(square(0), 0);
}

TEST(SquareFunction, HandlesNegativeInput) {
    EXPECT_EQ(square(-3), 9);
}

TEST(IsEvenFunction, HandlesEvenInput) {
    EXPECT_TRUE(is_even(10));
}

TEST(IsEvenFunction, HandlesOddInput) {
    EXPECT_FALSE(is_even(7));
}

// === Main Function ===

int main(int argc, char **argv) {
    std::cout << "Running math_utils tests..." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// tajul is the ghost
