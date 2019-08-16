/*
 https://cses.fi/problemset/task/1750
 Planets Queries I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    30

int main() {
    static int aa[N][K];
    int n, q, i, k, m;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i][0]), aa[i][0]--;
    for (k = 1; k < K; k++)
        for (i = 0; i < n; i++)
            aa[i][k] = aa[aa[i][k - 1]][k - 1];
    while (q--) {
        scanf("%d%d", &i, &m), i--;
        for (k = K - 1; k >= 0; k--)
            if (1 << k <= m) {
                i = aa[i][k];
                m -= 1 << k;
            }
        printf("%d\n", i + 1);
    }
    return 0;
}
