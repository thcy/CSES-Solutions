/*
 https://cses.fi/problemset/task/1634
 Minimizing Coins
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define X    1000000
#define INF    0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int main() {
    static int dp[X + 1];
    int n, x, y, c;
    
    scanf("%d%d", &n, &x);
    memset(dp, 0x3f, (x + 1) * sizeof *dp);
    dp[0] = 0;
    while (n--) {
        scanf("%d", &c);
        for (y = c; y <= x; y++)
            dp[y] = min(dp[y], dp[y - c] + 1);
    }
    printf("%d\n", dp[x] == INF ? -1 : dp[x]);
    return 0;
}
