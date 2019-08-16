/*
 https://cses.fi/problemset/task/1695
 Police Chase
 practice with Dukkha
 */
#include <stdio.h>

#define N    500
#define M    1000

struct L {
    struct L *next;
    int h;
} aa[N];

int ij[M], cc[M * 4];
int dd[N];

void link(int i, int h) {
    static struct L l91[M * 4], *l = l91;
    
    l->h = h;
    l->next = aa[i].next; aa[i].next = l++;
}

int bfs(int n, int s, int t) {
    static int qq[N];
    int h, i, j, head, cnt, d;
    
    for (i = 0; i < n; i++)
        dd[i] = n;
    dd[s] = 0;
    head = cnt = 0;
    qq[head + cnt++] = s;
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        d = dd[i] + 1;
        for (l = aa[i].next; l; l = l->next)
            if (cc[h = l->h]) {
                j = i ^ ij[h >> 2];
                if (dd[j] == n) {
                    dd[j] = d;
                    if (j == t)
                        return 1;
                    qq[head + cnt++] = j;
                }
            }
    }
    return 0;
}

int dfs(int n, int i, int t) {
    struct L *l;
    int h, j, d;
    
    if (i == t)
        return 1;
    d = dd[i] + 1;
    for (l = aa[i].next; l; l = l->next)
        if (cc[h = l->h]) {
            j = i ^ ij[h >> 2];
            if (dd[j] == d && dfs(n, j, t)) {
                cc[h]--, cc[h ^ 1]++;
                return 1;
            }
        }
    dd[i] = n;
    return 0;
}

int dinic(int n, int s, int t) {
    int f = 0;
    
    while (bfs(n, s, t))
        while (dfs(n, s, t))
            f++;
    return f;
}

int main() {
    int n, m, h, i, j;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        ij[h] = i ^ j;
        cc[h * 4 + 0] = 1;
        cc[h * 4 + 2] = 1;
        link(i, h * 4 + 0);
        link(j, h * 4 + 1);
        link(j, h * 4 + 2);
        link(i, h * 4 + 3);
    }
    printf("%d\n", dinic(n, 0, n - 1));
    for (i = 0; i < n; i++)
        if (dd[i] < n) {
            struct L *l;
            
            for (l = aa[i].next; l; l = l->next) {
                h = l->h;
                j = i ^ ij[h >> 2];
                if (dd[j] == n && (h & 1) == 0)
                    printf("%d %d\n", i + 1, j + 1);
            }
        }
    return 0;
}
