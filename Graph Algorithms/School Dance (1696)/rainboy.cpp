/*
 https://cses.fi/problemset/task/1696
 School Dance
 practice with Dukkha
 */
#include <stdio.h>

#define N    500
#define M    1000

struct L {
    struct L *next;
    int v;
} aa[N + 1];

int vv[N + 1], uu[N + 1], dd[N + 1];

void link(int u, int v) {
    static struct L l91[M], *l = l91;
    
    l->v = v;
    l->next = aa[u].next, aa[u].next = l++;
}

int bfs(int n) {
    static int qq[N];
    int u, head, cnt, d;
    
    head = cnt = 0;
    dd[0] = n;
    for (u = 1; u <= n; u++)
        if (vv[u] == 0) {
            dd[u] = 0;
            qq[head + cnt++] = u;
        } else
            dd[u] = n;
    while (cnt) {
        struct L *l;
        
        u = qq[cnt--, head++];
        d = dd[u] + 1;
        for (l = aa[u].next; l; l = l->next) {
            int v = l->v, w = uu[v];
            
            if (dd[w] == n) {
                dd[w] = d;
                if (w == 0)
                    return 1;
                qq[head + cnt++] = w;
            }
        }
    }
    return 0;
}

int dfs(int n, int u) {
    struct L *l;
    int d;
    
    if (u == 0)
        return 1;
    d = dd[u] + 1;
    for (l = aa[u].next; l; l = l->next) {
        int v = l->v, w = uu[v];
        
        if (dd[w] == d && dfs(n, w)) {
            vv[u] = v;
            uu[v] = u;
            return 1;
        }
    }
    dd[u] = n;
    return 0;
}

int hopcroft_karp(int n) {
    int m = 0;
    
    while (bfs(n)) {
        int u;
        
        for (u = 1; u <= n; u++)
            if (vv[u] == 0 && dfs(n, u))
                m++;
    }
    return m;
}

int main() {
    int n, n_, m, u, v;
    
    scanf("%d%d%d", &n, &n_, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        link(u, v);
    }
    printf("%d\n", hopcroft_karp(n));
    for (u = 1; u <= n; u++)
        if (vv[u])
            printf("%d %d\n", u, vv[u]);
    return 0;
}
