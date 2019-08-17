/*
 https://cses.fi/problemset/task/1112
 Substrings
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000
#define M    100
#define C    26
#define MD    1000000007

int main() {
    static char cc[M + 1];
    static int ff[M], delta[M][C], dp[N + 1][M + 1];
    int n, m, i, j, j_, c, x;
    long long ans, q;
    
    scanf("%d%s", &n, cc);
    m = strlen(cc);
    ff[0] = -1;
    for (j = 1; j < m; j++) {
        i = ff[j - 1] + 1;
        while (cc[i] != cc[j]) {
            if (i == 0) {
                i--;
                break;
            }
            i = ff[i - 1] + 1;
        }
        ff[j] = i;
    }
    for (j = 0; j < m; j++)
        for (c = 0; c < C; c++) {
            i = j;
            while (cc[i] != c + 'A') {
                if (i == 0) {
                    i--;
                    break;
                }
                i = ff[i - 1] + 1;
            }
            delta[j][c] = i + 1;
        }
    dp[0][0] = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if ((x = dp[i][j]) == 0)
                continue;
            for (c = 0; c < C; c++) {
                j_ = delta[j][c];
                dp[i + 1][j_] = (dp[i + 1][j_] + x) % MD;
            }
        }
    ans = 0;
    q = 1;
    for (i = n; i >= m; i--) {
        ans = (ans + dp[i][m] * q) % MD;
        q = q * 26 % MD;
    }
    printf("%lld\n", ans);
    return 0;
}
