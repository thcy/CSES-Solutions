/*
 https://cses.fi/problemset/task/1711
 Distinct Routes
 practice with Dukkha
 */
#include <stdio.h>

#define N    500
#define M    1000

struct L {
    struct L *next;
    int h;
} aa[N * 2];

int ij[M + N], cc[(M + N) * 2], dd[N * 2];

int bfs(int n, int s, int t) {
    static int qq[N * 2];
    int head, cnt, h, i, j, d;
    
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
                j = i ^ ij[h >> 1];
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
            j = i ^ ij[h >> 1];
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

void link(int i, int j, int h, int c) {
    static struct L l91[(M + N) * 2], *l = l91;
    
    ij[h] = i ^ j;
    cc[h << 1] = c;
    l->h = h << 1;
    l->next = aa[i].next, aa[i].next = l++;
    l->h = h << 1 ^ 1;
    l->next = aa[j].next, aa[j].next = l++;
}

int qq[N];

int path(int i, int t) {
    int cnt = 0;
    
    while (i != t) {
        struct L *l;
        int h;
        
        qq[cnt++] = i;
        for (l = aa[i].next; l; l = l->next)
            if (((h = l->h) & 1) == 0 && cc[h ^ 1]) {
                cc[h]++, cc[h ^ 1]--;
                i ^= ij[h >> 1];
                break;
            }
    }
    qq[cnt++] = t;
    return cnt;
}

int main() {
    int n, m, h, i, j, k, s, t, cnt;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i << 1 ^ 1, j << 1, h, 1);
    }
    for (i = 0; i < n; i++)
        link(i << 1, i << 1 ^ 1, m + i, n);
    s = 0, t = (n - 1) << 1 ^ 1;
    k = dinic(n * 2, s, t);
    printf("%d\n", k);
    while (k--) {
        cnt = path(s, t);
        printf("%d\n", cnt / 2);
        for (i = 0; i < cnt; i += 2)
            printf("%d ", (qq[i] >> 1) + 1);
        printf("\n");
    }
    return 0;
}
