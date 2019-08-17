/*
 https://cses.fi/problemset/task/1654
 Bit Problem
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    20    /* K = ceil(log2(A)) */
#define A    (1 << K)

int main() {
    static int aa[N], dp[A], dq[A];
    int n, h, i, a;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    for (i = 0; i < n; i++) {
        a = aa[i];
        dp[a]++;
        dq[a]++;
    }
    for (h = 0; h < K; h++)
        for (a = 0; a < A; a++)
            if (a & 1 << h)
                dp[a] += dp[a ^ 1 << h];
            else
                dq[a] += dq[a ^ 1 << h];
    for (i = 0; i < n; i++) {
        a = aa[i];
        printf("%d %d %d\n", dp[a], dq[a], n - dp[a ^ A - 1]);
    }
    return 0;
}
