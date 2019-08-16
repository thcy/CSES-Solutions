/*
 https://cses.fi/problemset/task/1194
 Monsters
 practice with Dukkha
 */
#include <stdio.h>

#define N    2500

int main() {
    static char cc[N][N + 1], s[N * N + 1];
    static int qq[N * N * 2], dd[N][N], hh[N][N];
    int ii[] = { -1, 0, 0, 1 };
    int jj[] = { 0, -1, 1, 0 };
    char pp[] = "ULRD";
    int n, m, h, i, j, d, head, cnt;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            dd[i][j] = n * m;
    head = cnt = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (cc[i][j] == 'M') {
                dd[i][j] = 0;
                qq[head + cnt++] = i;
                qq[head + cnt++] = j;
            }
    while (cnt) {
        i = qq[cnt--, head++], j = qq[cnt--, head++], d = dd[i][j] + 1;
        for (h = 0; h < 4; h++) {
            int i_ = i + ii[h], j_ = j + jj[h];
            
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && cc[i_][j_] != '#' && dd[i_][j_] > d) {
                dd[i_][j_] = d;
                qq[head + cnt++] = i_;
                qq[head + cnt++] = j_;
            }
        }
    }
    head = cnt = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (cc[i][j] == 'A') {
                dd[i][j] = 0;
                qq[head + cnt++] = i;
                qq[head + cnt++] = j;
                goto out;
            }
out:
    while (cnt > 0) {
        i = qq[cnt--, head++], j = qq[cnt--, head++];
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            printf("YES\n");
            printf("%d\n", dd[i][j]);
            while (dd[i][j]) {
                h = hh[i][j];
                s[dd[i][j] - 1] = pp[h];
                i -= ii[h];
                j -= jj[h];
            }
            printf("%s\n", s);
            return 0;
        }
        d = dd[i][j] + 1;
        for (h = 0; h < 4; h++) {
            int i_ = i + ii[h], j_ = j + jj[h];
            
            if (cc[i_][j_] != '#' && dd[i_][j_] > d) {
                dd[i_][j_] = d;
                hh[i_][j_] = h;
                qq[head + cnt++] = i_;
                qq[head + cnt++] = j_;
            }
        }
    }
    printf("NO\n");
    return 0;
}
