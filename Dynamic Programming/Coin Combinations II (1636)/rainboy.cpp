/*
 https://cses.fi/problemset/task/1636
 Coin Combinations II
 practice with Dukkha
 */
#include <stdio.h>

#define X    1000000
#define MD    1000000007

int main() {
    static int dp[X + 1];
    int n, x;
    
    scanf("%d%d", &n, &x);
    dp[0] = 1;
    while (n--) {
        int c, y;
        
        scanf("%d", &c);
        for (y = c; y <= x; y++)
            dp[y] = (dp[y] + dp[y - c]) % MD;
    }
    printf("%d\n", dp[x]);
    return 0;
}
