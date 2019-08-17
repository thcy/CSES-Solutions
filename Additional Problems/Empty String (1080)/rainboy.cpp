/*
 https://cses.fi/problemset/task/1080
 Empty String
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    500
#define MD    1000000007

int ch[N + 1][N + 1];

void init(int n) {
    int i, j;
    
    ch[0][0] = 1;
    for (i = 1; i <= n; i++) {
        ch[i][0] = 1;
        for (j = 1; j <= i; j++)
            ch[i][j] = (ch[i - 1][j] + ch[i - 1][j - 1]) % MD;
    }
}

int main() {
    static char cc[1 + N + 1];
    static long long dp[N + 1][N + 1];
    int n, h, i, j;
    
    scanf("%s", cc + 1);
    n = strlen(cc + 1);
    init(n);
    for (i = 1; i <= n; i++)
        dp[i][i - 1] = 1;
    for (h = n; h >= 1; h--)
        for (j = h + 1; j <= n; j += 2) {
            long long x = 0;
            
            for (i = h; i < j; i += 2)
                if (cc[i] == cc[j])
                    x = (x + dp[h][i - 1] * dp[i + 1][j - 1] % MD * ch[(j - h + 1) / 2][(i - h) / 2]) % MD;
            dp[h][j] = x;
        }
    printf("%lld\n", dp[1][n]);
    return 0;
}
