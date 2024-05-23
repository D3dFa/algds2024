#include <stdio.h>
#include "dp.h"

// Массив для хранения количества чисел
int dp[MAX_N + 1][MAX_K + 1];

void initialize_dp() {
    // Инициализация базового случая: одно 0-значное число с суммой 0
    dp[0][0] = 1;
}

void calculate_dp(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
            for (int digit = 0; digit <= 9; ++digit) {
                if (j >= digit) {
                    dp[i][j] += dp[i - 1][j - digit];
                }
            }
        }
    }
}

void process_input_and_calculate() {
    int n, k;
    printf("Введите количество цифр (n): ");
    scanf("%d", &n);
    printf("Введите требуемую сумму цифр (k): ");
    scanf("%d", &k);

    if (n > MAX_N || k > MAX_K) {
        printf("Превышены ограничения на n или k.\n");
        return;
    }

    initialize_dp();
    calculate_dp(n, k);

    printf("Количество %d-значных чисел с суммой цифр %d равно %d\n", n, k, dp[n][k]);
}
