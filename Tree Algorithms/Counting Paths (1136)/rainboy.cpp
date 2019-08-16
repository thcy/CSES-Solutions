/*
 https://cses.fi/problemset/task/1136
 Counting Paths
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    17    /* K = floor(log2(N)) */

struct L {
    struct L *next;
    int j;
} aa[N];

int dd[N], pp[N][K + 1], ll[N], rr[N], cc[N];

void link(int i, int j) {
    static struct L ll_[N * 2], *l = ll_;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

void dfs(int p, int i, int d) {
    struct L *l;
    int k;
    
    dd[i] = d;
    pp[i][0] = p;
    for (k = 1; 1 << k <= d; k++)
        pp[i][k] = pp[pp[i][k - 1]][k - 1];
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p)
            dfs(i, l->j, d + 1);
}

int lca(int i, int j) {
    int k;
    
    if (dd[i] < dd[j])
        return lca(j, i);
    for (k = K; k >= 0; k--)
        if (1 << k <= dd[i] - dd[j])
            i = pp[i][k];
    if (i == j)
        return i;
    for (k = K; k >= 0; k--)
        if (1 << k <= dd[i] && pp[i][k] != pp[j][k])
            i = pp[i][k], j = pp[j][k];
    return pp[i][0];
}

int dfs2(int p, int i) {
    struct L *l;
    int c = cc[i];
    
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p)
            c += dfs2(i, l->j);
    cc[i] = c += ll[i];
    return c - rr[i];
}

int main() {
    int n, m, h, i, j;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0, 0);
    while (m--) {
        int i, j, a;
        
        scanf("%d%d", &i, &j), i--, j--;
        a = lca(i, j);
        if (i == a) {
            ll[j]++;
            rr[i]++;
        } else if (j == a) {
            ll[i]++;
            rr[j]++;
        } else {
            ll[i]++;
            ll[j]++;
            rr[a]++;
            cc[a]--;
        }
    }
    dfs2(-1, 0);
    for (i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
