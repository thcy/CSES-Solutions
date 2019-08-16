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

int ii[M], jj[M], cc[M], ff[M], dd[N];

void link(int i, int h) {
    static struct L l91[M * 2], *l = l91;
    
    l->h = h;
    l->next = aa[i].next, aa[i].next = l++;
}

int bfs(int n, int s, int t) {
    static int qq[N];
    int i, head, cnt, d;
    
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
            int h = l->h, j = i ^ ii[h] ^ jj[h];
            
            if (dd[j] == n && ((i == ii[h] && ff[h] < cc[h]) || (i == jj[h] && ff[h]))) {
                dd[j] = d;
                if (j == t)
                    return 1;
                qq[head + cnt++] = j;
            }
        }
    }
    return 0;
}

int dfs(int n, int i, int t, int c) {
    struct L *l;
    int d;
    
    if (i == t || c == 0)
        return c;
    d = dd[i] + 1;
    for (l = aa[i].next; l; l = l->next) {
        int h = l->h, j = i ^ ii[h] ^ jj[h];
        
        if (dd[j] == d) {
            int c_ = i == ii[h] ? cc[h] - ff[h] : ff[h];
            int f = dfs(n, j, t, c < c_ ? c : c_);
            
            if (f) {
                ff[h] += i == ii[h] ? f : -f;
                return f;
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
        ii[h] = i, jj[h] = j;
        cc[h] = c;
        link(i, h), link(j, h);
    }
    printf("%lld\n", dinic(n, 0, n - 1));
    return 0;
}
