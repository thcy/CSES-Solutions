/*
 https://cses.fi/problemset/task/1653
 Elevator Rides
 practice with Dukkha
 */
#include <stdio.h>

#define N    20

int main() {
    static int aa[N], dp[1 << N], dq[1 << N];
    int n, x, i, b, b_, p, q, a;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    for (b = 0; b < 1 << n; b++)
        dp[b] = n + 1;
    dp[0] = 0, dq[0] = x;
    for (b = 0; b < 1 << n; b++)
        for (i = 0; i < n; i++)
            if (!(b & 1 << i)) {
                p = dp[b], q = dq[b], a = aa[i];
                if (q + a <= x)
                    q += a;
                else {
                    p++;
                    q = a;
                }
                b_ = b | 1 << i;
                if (dp[b_] > p || (dp[b_] == p && dq[b_] > q))
                    dp[b_] = p, dq[b_] = q;
            }
    printf("%d\n", dp[(1 << n) - 1]);
    return 0;
}
