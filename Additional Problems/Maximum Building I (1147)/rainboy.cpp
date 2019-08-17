/*
 https://cses.fi/problemset/task/1147
 Building
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000

int main() {
    static char cc[N][N + 1];
    static int ll[N][N], rr[N][N];
    int n, m, i, j, ans, h, l, r;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            if (cc[i][j] == '*')
                ll[i][j] = 0;
            else
                ll[i][j] = (j == 0 ? 0 : ll[i][j - 1]) + 1;
        for (j = m - 1; j >= 0; j--)
            if (cc[i][j] == '*')
                rr[i][j] = 0;
            else
                rr[i][j] = (j == m - 1 ? 0 : rr[i][j + 1]) + 1;
    }
    ans = 0;
    for (j = 0; j < m; j++) {
        h = 0, l = m, r = m;
        for (i = 0; i < n; i++) {
            if (cc[i][j] == '*')
                h = 0, l = m, r = m;
            else {
                h++;
                if (l > ll[i][j])
                    l = ll[i][j];
                if (r > rr[i][j])
                    r = rr[i][j];
            }
            if (ans < (l + r - 1) * h)
                ans = (l + r - 1) * h;
        }
    }
    printf("%d\n", ans);
    return 0;
}
