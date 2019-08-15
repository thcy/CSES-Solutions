/*
 https://cses.fi/problemset/task/1638
 Grid Paths
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000
#define MD    1000000007

int main() {
    static char s[N + 1];
    static int dp[N][N];
    int n, i, j;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        for (j = 0; j < n; j++)
            if (s[j] == '.') {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    if (i > 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MD;
                    if (j > 0)
                        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MD;
                }
            }
    }
    printf("%d\n", dp[n - 1][n - 1]);
    return 0;
}
