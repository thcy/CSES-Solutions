/*
 https://cses.fi/problemset/task/1637
 Removing Digits
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000000

int main() {
    static int dp[N + 1];
    int n, i, j, d, x_, x;
    
    scanf("%d", &n);
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        x_ = i;
        j = i;
        while (j > 0) {
            d = j % 10;
            if (d != 0 && x_ > (x = dp[i - d]))
                x_ = x;
            j /= 10;
        }
        dp[i] = x_ + 1;
    }
    printf("%d\n", dp[n]);
    return 0;
}
