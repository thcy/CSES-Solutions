/*
 https://cses.fi/problemset/task/1750
 Planets Queries I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    30

int main() {
    static int aa[K][N];
    int n, q, i, k, m;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[0][i]), aa[0][i]--;
    for (k = 1; k < K; k++)
        for (i = 0; i < n; i++)
            aa[k][i] = aa[k - 1][aa[k - 1][i]];
    while (q--) {
        scanf("%d%d", &i, &m), i--;
        for (k = K - 1; k >= 0; k--)
            if (1 << k <= m) {
                i = aa[k][i];
                m -= 1 << k;
            }
        printf("%d\n", i + 1);
    }
    return 0;
}
