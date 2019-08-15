/*
 https://cses.fi/problemset/task/1744
 Rectangle Cutting
 practice with Dukkha
 */
#include <stdio.h>

#define A    500
#define B    500

int main() {
    static int dp[A + 1][B + 1];
    int a, b, p, q, p_, q_, x_, x;
    
    scanf("%d%d", &a, &b);
    for (p = 1; p <= a; p++)
        for (q = 1; q <= b; q++) {
            if (p == q) {
                dp[p][q] = 0;
                continue;
            }
            x_ = p * q;
            for (p_ = 1; p_ < p; p_++)
                if (x_ > (x = dp[p_][q] + dp[p - p_][q]))
                    x_ = x;
            for (q_ = 1; q_ < q; q_++)
                if (x_ > (x = dp[p][q_] + dp[p][q - q_]))
                    x_ = x;
            dp[p][q] = x_ + 1;
        }
    printf("%d\n", dp[a][b]);
    return 0;
}
