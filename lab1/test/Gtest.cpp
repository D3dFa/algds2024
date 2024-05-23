#include <gtest/gtest.h>
extern "C" {
    #include "dp.h"
}

TEST(InitializeDpTest, BaseCase) {
    initialize_dp();
    EXPECT_EQ(dp[0][0], 1);
    for (int i = 1; i <= MAX_N; ++i) {
        EXPECT_EQ(dp[i][0], 0);
    }
}

TEST(CalculateDpTest, ValidInput) {
    initialize_dp();

    calculate_dp(2, 1);
    EXPECT_EQ(dp[2][1], 2); 
    // 01, 10

    calculate_dp(2, 5);
    EXPECT_EQ(dp[2][5], 6); 
    // 05, 14, 23, 32, 41, 50

    calculate_dp(3, 6);
    EXPECT_EQ(dp[3][6], 28); 
    // 006, 060, 006
    // 411, 141, 114
    // 033, 303, 330
    // 510, 501, 051, 015, 105, 150
    // аналогично для 420, 123
    // 222
    // в сумме 28
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


