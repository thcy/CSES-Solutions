/*
 https://cses.fi/problemset/task/1688
 Company Queries II
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define LN    17    /* LN = floor(log2(N - 1)) */

int main() {
    static int dd[N], pp[LN + 1][N];
    int n, q, p, i, j, k, tmp;
    
    scanf("%d%d", &n, &q);
    for (i = 1; i < n; i++) {
        scanf("%d", &p), p--;
        dd[i] = dd[p] + 1;
        pp[0][i] = p;
    }
    for (k = 1; k <= LN; k++)
        for (i = 0; i < n; i++)
            pp[k][i] = pp[k - 1][pp[k - 1][i]];
    while (q--) {
        scanf("%d%d", &i, &j), i--, j--;
        if (dd[i] < dd[j])
            tmp = i, i = j, j = tmp;
        if (dd[i] != dd[j])
            for (k = LN; k >= 0; k--)
                if (1 << k <= dd[i] - dd[j])
                    i = pp[k][i];
        if (i != j) {
            for (k = LN; k >= 0; k--)
                if (1 << k <= dd[i] && pp[k][i] != pp[k][j]) {
                    i = pp[k][i];
                    j = pp[k][j];
                }
            i = pp[0][i];
        }
        printf("%d\n", i + 1);
    }
    return 0;
}
