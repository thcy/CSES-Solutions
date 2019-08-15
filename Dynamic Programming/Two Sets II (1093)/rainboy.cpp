/*
 practice with Dukkha
 https://cses.fi/problemset/task/1093
 Two Sets II
 */
#include <stdio.h>

#define M    62625    /* 500 * 501 / 4 */
#define MD    1000000007

int main() {
    static int dp[1 + M];
    int n, m, i, j;
    
    scanf("%d", &n);
    if (n % 4 == 1 || n % 4 == 2) {
        printf("0\n");
        return 0;
    }
    m = n * (n + 1) / 4;
    dp[0] = 1;
    for (i = 1; i <= n; i++)
        for (j = m; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % MD;
    printf("%lld\n", (long long) dp[m] * (MD + 1) / 2 % MD);
    return 0;
}
