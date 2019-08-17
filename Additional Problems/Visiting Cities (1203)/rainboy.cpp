/*
 https://cses.fi/problemset/task/1203
 Visiting Cities
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000
#define INF    0x3f3f3f3f3f3f3f3f

struct L {
    struct L *next;
    int j, c;
} aa[N];

struct V {
    int i;    /* for heap */
    int i_;
} vv[N], *pq[1 + N];

int cnt;

long long dd[N];
int pp[N], qq[N];
char used[N], marked[N];

#define LT(u, v) (dd[(u)->i_] < dd[(v)->i_])

int i2(int i) {
    return (i *= 2) > cnt ? 0 : i < cnt && LT(pq[i + 1], pq[i]) ? i + 1 : i;
}

void pq_up(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i / 2) && LT(u, pq[j]); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_dn(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i2(i)) && LT(pq[j], u); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_add(struct V *u) {
    u->i = ++cnt;
    pq_up(u);
}

struct V *pq_remove_first() {
    struct V *u = pq[1], *v = pq[cnt--];
    
    v->i = 1;
    pq_dn(v);
    return u;
}

void link(int i, int j, int c) {
    static struct L l91[M], *l = l91;
    
    l->j = j, l->c = c;
    l->next = aa[i].next; aa[i].next = l++;
}

int i_;

void dijkstra(int n) {
    int i, j, c;
    long long d;
    
    for (i = 0; i < n; i++) {
        vv[i].i_ = i;
        dd[i] = INF;
    }
    dd[0] = 0;
    pq_add(&vv[0]);
    while (cnt) {
        struct V *u = pq_remove_first();
        struct L *l;
        
        i = u->i_;
        d = dd[i];
        for (l = aa[i].next; l; l = l->next) {
            j = l->j, c = l->c;
            if (dd[j] == INF) {
                dd[j] = d + c;
                pp[j] = i;
                pq_add(&vv[j]);
            } else if (dd[j] > d + c) {
                dd[j] = d + c;
                pp[j] = i;
                pq_up(&vv[j]);
            }
        }
    }
}

void dfs(int i) {
    struct L *l;
    long long d = dd[i];
    
    if (marked[i] && dd[i] > dd[i_])
        i_ = i;
    if (used[i])
        return;
    used[i] = 1;
    for (l = aa[i].next; l; l = l->next) {
        int j = l->j, c = l->c;
        
        if (dd[j] == d + c)
            dfs(j);
    }
}

void solve(int n) {
    int i;
    
    cnt = 0;
    for (i = n - 1; i != 0; i = pp[i]) {
        marked[i] = used[i] = 1;
        qq[cnt++] = i;
    }
    marked[0] = used[0] = 1;
    qq[cnt++] = 0;
    i_ = 0;
    while (cnt) {
        i = qq[--cnt];
        if (i != i_)
            marked[i] = 0;
        used[i] = 0;
        dfs(i);
    }
    cnt = 0;
    for (i = 0; i < n; i++)
        if (marked[i])
            qq[cnt++] = i;
}

int main() {
    int n, m, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        link(i, j, c);
    }
    dijkstra(n);
    solve(n);
    printf("%d\n", cnt);
    for (i = 0; i < cnt; i++)
        printf("%d ", qq[i] + 1);
    printf("\n");
    return 0;
}
