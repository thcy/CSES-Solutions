/*
 https://cses.fi/problemset/task/1135
 Distance Queries
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    17    /* K = floor(log2(N - 1)) */

struct L {
    struct L *next;
    int j;
} aa[N];

int dd[N], pp[N][K + 1];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
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

int main() {
    int n, q, h, i, j;
    
    scanf("%d%d", &n, &q);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0, 0);
    while (q--) {
        int i, j, a;
        
        scanf("%d%d", &i, &j), i--, j--;
        a = lca(i, j);
        printf("%d\n", dd[i] + dd[j] - dd[a] * 2);
    }
    return 0;
}
