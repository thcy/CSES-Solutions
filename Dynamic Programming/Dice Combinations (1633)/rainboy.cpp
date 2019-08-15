/*
 https://cses.fi/problemset/task/1633
 Dice Combinations
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000000
#define MD    1000000007

int main() {
    static int dp[N + 1];
    int n, i, j;
    long long x;
    
    scanf("%d", &n);
    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        x = 0;
        for (j = 1; j <= 6 && j <= i; j++)
            x += dp[i - j];
        dp[i] = x % MD;
    }
    printf("%d\n", dp[n]);
    return 0;
}
