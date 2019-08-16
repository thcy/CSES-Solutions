/*
 https://cses.fi/problemset/task/1723
 Graph Paths I
 practice with Dukkha
 */
#include <stdio.h>

#define N    100
#define MD    1000000007

void mult(int aa[][N], int bb[][N], int cc[][N], int n) {
    int i, j, k;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            int c = 0;
            
            for (k = 0; k < n; k++)
                c = (c + (long long) aa[i][k] * bb[k][j]) % MD;
            cc[i][j] = c;
        }
}

void power(int aa[][N], int pp[][N], int tt[][N], int n, int k) {
    if (k == 0) {
        int i, j;
        
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                pp[i][j] = i == j;
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
    static int aa[N][N], pp[N][N], tt[N][N];
    int n, m, k, i, j;
    
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        aa[i][j]++;
    }
    power(aa, pp, tt, n, k);
    printf("%d\n", pp[0][n - 1]);
    return 0;
}
