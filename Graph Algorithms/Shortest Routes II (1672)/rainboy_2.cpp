/*
 https://cses.fi/problemset/task/1672
 Shortest Routes II
 practice with Dukkha
 */
#include <stdio.h>

#define N    500
#define INF    0x3f3f3f3f3f3f3f3fLL

int main() {
    static long long aa[N][N];
    int n, m, q, i, j, k, c;
    long long a;
    
    scanf("%d%d%d", &n, &m, &q);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            aa[i][j] = i == j ? 0 : INF;
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        if (aa[i][j] > c)
            aa[i][j] = aa[j][i] = c;
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (aa[i][j] > (a = aa[i][k] + aa[k][j]))
                    aa[i][j] = aa[j][i] = a;
    while (q--) {
        scanf("%d%d", &i, &j), i--, j--;
        printf("%lld\n", (a = aa[i][j]) == INF ? -1 : a);
    }
    return 0;
}
