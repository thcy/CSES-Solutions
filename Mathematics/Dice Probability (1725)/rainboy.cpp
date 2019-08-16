/*
 https://cses.fi/problemset/task/1725
 Dice Probability
 practice with Dukkha
 */
#include <stdio.h>

#define N    100
#define M    (N * 6)

int main() {
    static double dp[M + 1];
    int n, m, a, b, h, j;
    double ans;
    
    scanf("%d%d%d", &n, &a, &b);
    m = n * 6;
    dp[0] = 1;
    while (n--)
        for (j = m; j >= 0; j--) {
            double x = dp[j] / 6;
            
            for (h = 1; h <= 6 && j + h <= m; h++)
                dp[j + h] += x;
            dp[j] = 0;
        }
    ans = 0;
    for (j = a; j <= b; j++)
        ans += dp[j];
    printf("%.6f\n", ans);
    return 0;
}
