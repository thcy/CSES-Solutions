/*
 https://cses.fi/problemset/task/1724
 Graph Paths II
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100
#define INF    0x3f3f3f3f3f3f3f3f

void mult(long long aa[][N], long long bb[][N], long long cc[][N], int n) {
    int i, j, k;
    
    for (i = 0; i < n; i++) {
        long long *ci = cc[i];
        
        for (j = 0; j < n; j++)
            ci[j] = INF;
        for (k = 0; k < n; k++) {
            long long a = aa[i][k];
            
            if (a != INF) {
                long long *bk = bb[k], d;
                
                for (j = 0; j < n; j++)
                    if (ci[j] > (d = a + bk[j]))
                        ci[j] = d;
            }
        }
    }
}

void power(long long aa[][N], long long pp[][N], long long tt[][N], int n, int k) {
    if (k == 0) {
        int i, j;
        
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                pp[i][j] = i == j ? 0 : INF;
        return;
    }
    if (k % 2 == 0) {
        power(aa, tt, pp, n, k / 2);
        mult(tt, tt, pp, n);
    } else {
        power(aa, pp, tt, n, k / 2);
        mult(pp, pp, tt, n);
        mult(tt, aa, pp, n);
    }
}

int main() {
    static long long aa[N][N], pp[N][N], tt[N][N];
    int n, m, k, i, j, a;
    long long ans;
    
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; i++)
        memset(aa[i], 0x3f, n * sizeof *aa[i]);
    while (m--) {
        scanf("%d%d%d", &i, &j, &a), i--, j--;
        if (aa[i][j] > a)
            aa[i][j] = a;
    }
    power(aa, pp, tt, n, k);
    ans = pp[0][n - 1];
    printf("%lld\n", ans == INF ? -1 : ans);
    return 0;
}
