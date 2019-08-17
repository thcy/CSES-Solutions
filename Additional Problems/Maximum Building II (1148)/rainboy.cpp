/*
 https://cses.fi/problemset/task/1148
 Building II
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    1000

char cc[N][N + 1];

int ll[N][N], rr[N][N];
char alive[N][N];

struct E {
    int i, j;
} *ee[N + 1];

int kk[N + 1], pp[N + 1], aa[N][N], *qq;

int main() {
    int n, m, h, i, j, d, l, r;
    struct E *e;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (j = 0; j < m; j++) {
        d = 0;
        for (i = 0; i < n; i++) {
            if (cc[i][j] == '*')
                d = 0;
            else
                d++;
            kk[d]++;
        }
    }
    for (d = 0; d <= n; d++) {
        ee[d] = (struct E *) malloc(kk[d] * sizeof *ee[d]);
        kk[d] = 0;
    }
    for (j = 0; j < m; j++) {
        d = 0;
        for (i = 0; i < n; i++) {
            if (cc[i][j] == '*')
                d = 0;
            else
                d++;
            e = &ee[d][kk[d]++];
            e->i = i, e->j = j;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ll[i][j] = rr[i][j] = j;
    for (d = n; d > 0; d--) {
        for (h = 0; h < kk[d]; h++) {
            e = &ee[d][h];
            i = e->i, j = e->j;
            alive[i][j] = 1;
            l = r = j;
            if (j > 0 && alive[i][j - 1]) {
                l = ll[i][j - 1];
                pp[j - l]--;
            }
            if (j < m - 1 && alive[i][j + 1]) {
                r = rr[i][j + 1];
                pp[r - j]--;
            }
            rr[i][l] = r;
            ll[i][r] = l;
            pp[r - l + 1]++;
        }
        qq = aa[d - 1];
        for (j = 1; j <= m; j++)
            qq[j - 1] = pp[j];
        for (j = m - 2; j >= 0; j--)
            qq[j] += qq[j + 1];
        for (j = m - 2; j >= 0; j--)
            qq[j] += qq[j + 1];
    }
    for (d = 0; d < n; d++) {
        for (j = 0; j < m; j++)
            printf("%d ", aa[d][j]);
        printf("\n");
    }
    return 0;
}
