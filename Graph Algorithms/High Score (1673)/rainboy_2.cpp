/*
 https://cses.fi/problemset/task/1673
 High Score
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    2500
#define M    5000
#define INF    0x3f3f3f3f3f3f3f3fLL

struct L {
    struct L *next;
    int j;
} aa[N + 1];

void link(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

char used[N + 1];

void dfs(int i) {
    struct L *l;
    
    if (used[i])
        return;
    used[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        dfs(l->j);
}

int uu[M], vv[M], ww[M];
long long dd[N + 1];

int relax(int m) {
    int h, u, v, w, updated;
    long long d;
    
    updated = 0;
    for (h = 0; h < m; h++) {
        u = uu[h], v = vv[h], w = ww[h];
        if (used[u] && used[v] && dd[u] != INF && dd[v] > (d = dd[u] + w)) {
            updated = 1;
            dd[v] = d;
        }
    }
    return updated;
}

int main() {
    int n, m, h, u, v, w;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d%d", &u, &v, &w), w = -w;
        uu[h] = u, vv[h] = v, ww[h] = w;
        link(vv[h], uu[h]);
    }
    dfs(n);
    memset(dd, 0x3f, (n + 1) * sizeof *dd);
    dd[1] = 0;
    for (h = 1; h < n; h++)
        relax(m);
    printf("%lld\n", relax(m) ? -1 : dd[n] == INF ? -999999999999999999LL : -dd[n]);
    return 0;
}
