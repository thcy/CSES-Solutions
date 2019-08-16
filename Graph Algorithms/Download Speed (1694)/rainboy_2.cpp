/*
 https://cses.fi/problemset/task/1694
 Download Speed
 practice with Dukkha
 */
#include <stdio.h>

#define N    500
#define M    1000
#define INF    0x3f3f3f3f

struct L {
    struct L *next;
    int h;
} aa[N];

int ij[M], cc[M * 2], dd[N];

void link(int i, int h) {
    static struct L l91[M * 2], *l = l91;
    
    l->h = h;
    l->next = aa[i].next, aa[i].next = l++;
}

int bfs(int n, int s, int t) {
    static int qq[N];
    int h, i, j, head, cnt, d;
    
    for (i = 0; i < n; i++)
        dd[i] = n;
    head = cnt = 0;
    dd[s] = 0;
    qq[head + cnt++] = s;
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        d = dd[i] + 1;
        for (l = aa[i].next; l; l = l->next) {
            h = l->h;
            if (cc[h]) {
                j = i ^ ij[h >> 1];
                if (dd[j] == n) {
                    dd[j] = d;
                    if (j == t)
                        return 1;
                    qq[head + cnt++] = j;
                }
            }
        }
    }
    return 0;
}

int dfs(int n, int i, int t, int c) {
    struct L *l;
    int h, j, d, f;
    
    if (i == t || c == 0)
        return c;
    d = dd[i] + 1;
    for (l = aa[i].next; l; l = l->next) {
        h = l->h;
        if (cc[h]) {
            j = i ^ ij[h >> 1];
            if (dd[j] == d) {
                f = dfs(n, j, t, c < cc[h] ? c : cc[h]);
                if (f) {
                    cc[h] -= f, cc[h ^ 1] += f;
                    return f;
                }
            }
        }
    }
    dd[i] = n;
    return 0;
}

long long dinic(int n, int s, int t) {
    long long sum = 0;
    
    while (bfs(n, s, t)) {
        int f;
        
        while ((f = dfs(n, s, t, INF)))
            sum += f;
    }
    return sum;
}

int main() {
    int n, m, h, i, j, c;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        cc[h * 2 + 0] = c;
        ij[h] = i ^ j;
        link(i, h * 2 + 0), link(j, h * 2 + 1);
    }
    printf("%lld\n", dinic(n, 0, n - 1));
    return 0;
}
