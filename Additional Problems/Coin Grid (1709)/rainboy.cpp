/*
 https://cses.fi/problemset/task/1709
 Coin Grid
 practice with Dukkha
 */
#include <stdio.h>

#define N    100

struct L {
    struct L *next;
    int v;
} aa[N + 1];

void link(int u, int v) {
    static struct L l91[N * N], *l = l91;
    
    l->v = v;
    l->next = aa[u].next, aa[u].next = l++;
}

int dd[N + 1], vv[N + 1], uu[N + 1];

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

int dfs(int u, int n) {
    struct L *l;
    int d;
    
    if (u == 0)
        return 1;
    d = dd[u] + 1;
    for (l = aa[u].next; l; l = l->next) {
        int v = l->v, w = uu[v];
        
        if (dd[w] == d && dfs(w, n)) {
            vv[u] = v, uu[v] = u;
            return 1;
        }
    }
    dd[u] = n;
    return 0;
}

int hopcroft_karp(int n) {
    int u, m = 0;
    
    while (bfs(n))
        for (u = 1; u <= n; u++)
            if (vv[u] == 0 && dfs(u, n))
                m++;
    return m;
}

int main() {
    static char s[N + 1];
    int n, u, v;
    
    scanf("%d", &n);
    for (u = 1; u <= n; u++) {
        scanf("%s", s);
        for (v = 1; v <= n; v++)
            if (s[v - 1] == 'o')
                link(u, v);
    }
    printf("%d\n", hopcroft_karp(n));
    for (u = 1; u <= n; u++) {
        if (vv[u] == 0)
            continue;
        if (dd[u] == n)
            printf("1 %d\n", u);
        else
            printf("2 %d\n", vv[u]);
    }
    return 0;
}
