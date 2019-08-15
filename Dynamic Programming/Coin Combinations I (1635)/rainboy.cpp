/*
 https://cses.fi/problemset/task/1635
 Coin Combinations I
 practice with Dukkha
 */
#include <stdio.h>

#define N    100
#define X    1000000
#define MD    1000000007

int main() {
    static int cc[N], dp[X + 1];
    int n, x, i, y;
    long long s;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &cc[i]);
    dp[0] = 1;
    for (y = 1; y <= x; y++) {
        s = 0;
        for (i = 0; i < n; i++)
            if (y >= cc[i])
                s += dp[y - cc[i]];
        dp[y] = s % MD;
    }
    printf("%d\n", dp[x]);
    return 0;
}
