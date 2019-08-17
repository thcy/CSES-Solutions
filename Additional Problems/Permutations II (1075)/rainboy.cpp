/*
 https://cses.fi/problemset/task/1075
 Permutations II
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000
#define MD    1000000007

int main() {
    static int dp0[N + 1][N + 1], dp1[N + 1][N + 1];
    int n, k, a, x;
    
    scanf("%d", &n);
    dp0[1][0] = 1;
    for (k = 2; k <= n; k++)
        for (a = 0; a < k; a++) {
            x = 0;
            x = (x + (long long) dp0[k - 1][a + 1] * (a + 1)) % MD;
            x = (x + (long long) dp1[k - 1][a + 1] * a) % MD;
            x = (x + (long long) dp0[k - 1][a] * (k - a - 2)) % MD;
            x = (x + (long long) dp1[k - 1][a] * (k - a - 1)) % MD;
            dp0[k][a] = x;
            x = dp1[k - 1][a];    /* replace */
            if (a > 0) {
                x = (x + (long long) dp0[k - 1][a - 1] * 2) % MD;
                x = (x + (long long) dp1[k - 1][a - 1]) % MD;
            }
            dp1[k][a] = x;
        }
    printf("%d\n", dp0[n][0]);
    return 0;
}
