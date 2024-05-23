#ifndef DP_H
#define DP_H

#define MAX_N 10
#define MAX_K 100

extern int dp[MAX_N + 1][MAX_K + 1];

void initialize_dp();
void calculate_dp(int n, int k);
void process_input_and_calculate();

#endif // DP_H
