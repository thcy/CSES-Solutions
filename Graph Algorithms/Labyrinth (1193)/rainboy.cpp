/*
 practice with Dukkha
 https://cses.fi/problemset/task/1193
 Labyrinth
 */
#include <stdio.h>

#define N    1000

int n, m;
char cc[N][N + 1], s[N * N + 1];
int dd[N][N], hh[N][N];
int ii[] = { -1, 0, 0, 1 };
int jj[] = { 0, -1, 1, 0 };
char zz[] = "ULRD";

int bfs(int i, int j) {
    static int qq[N * N * 2];
    int head, cnt, d, h;
    
    dd[i][j] = 0;
    head = cnt = 0;
    qq[head + cnt++] = i, qq[head + cnt++] = j;
    while (cnt) {
        i = qq[cnt--, head++], j = qq[cnt--, head++];
        d = dd[i][j] + 1;
        for (h = 0; h < 4; h++) {
            int i_ = i + ii[h];
            int j_ = j + jj[h];
            
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && cc[i_][j_] != '#' && dd[i_][j_] > d) {
                dd[i_][j_] = d;
                hh[i_][j_] = h;
                if (cc[i_][j_] == 'B')
                    return 1;
                qq[head + cnt++] = i_, qq[head + cnt++] = j_;
            }
        }
    }
    return 0;
}

int main() {
    int d, i, j;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            dd[i][j] = n * m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (cc[i][j] == 'A') {
                if (bfs(i, j)) {
                    printf("YES\n");
                    for (i = 0; i < n; i++)
                        for (j = 0; j < m; j++)
                            if (cc[i][j] == 'B')
                                goto out;
                out:
                    printf("%d\n", dd[i][j]);
                    for (d = dd[i][j]; d > 0; d--) {
                        int h = hh[i][j];
                        
                        s[d - 1] = zz[h];
                        i -= ii[h];
                        j -= jj[h];
                    }
                    printf("%s\n", s);
                } else {
                    printf("NO\n");
                }
                return 0;
            }
    return 0;
}
