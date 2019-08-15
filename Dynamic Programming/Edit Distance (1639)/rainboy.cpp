/*
 https://cses.fi/problemset/task/1639
 Edit Distance
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    5000
#define M    5000

int min(int a, int b) { return a < b ? a : b; }

int main() {
    static char s[N + 1], t[M + 1];
    static int dp[N + 1][M + 1];
    int n, m, i, j;
    
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (i = 0; i <= n; i++)
        dp[i][0] = i;
    for (j = 0; j <= m; j++)
        dp[0][j] = j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
    printf("%d\n", dp[n][m]);
    return 0;
}
