/*
 https://cses.fi/problemset/task/1686
 Coin Collector
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N], bb[N], bb_[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next, bb[j].next = l++;
}

void link_(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = i;
    l->next = bb_[j].next, bb_[j].next = l++;
}

int cc[N], qq[N];

void dfs1(int i) {
    static int cnt;
    struct L *l;
    
    if (cc[i])
        return;
    cc[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        dfs1(l->j);
    qq[cnt++] = i;
}

void dfs2(int j, int c) {
    struct L *l;
    
    if (cc[j])
        return;
    cc[j] = c;
    for (l = bb[j].next; l; l = l->next)
        dfs2(l->j, c);
}

int main() {
    static int ww[N];
    static long long ww_[N], dp[N];
    int n, m, h, i, j, c, ci, cj;
    long long x, ans;
    struct L *l;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &ww[i]);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    for (i = 0; i < n; i++)
        if (!cc[i])
            dfs1(i);
    memset(cc, 0, n * sizeof *cc);
    c = 0;
    for (h = n - 1; h >= 0; h--) {
        i = qq[h];
        if (!cc[i])
            dfs2(i, ++c);
    }
    for (i = 0; i < n; i++)
        cc[i]--;
    for (i = 0; i < n; i++)
        ww_[cc[i]] += ww[i];
    for (j = 0; j < n; j++) {
        cj = cc[j];
        for (l = bb[j].next; l; l = l->next) {
            ci = cc[l->j];
            if (ci < cj)
                link_(ci, cj);
        }
    }
    ans = 0;
    for (cj = 0; cj < c; cj++) {
        x = 0;
        for (l = bb_[cj].next; l; l = l->next)
            if (x < dp[ci = l->j])
                x = dp[ci];
        if (ans < (dp[cj] = x + ww_[cj]))
            ans = dp[cj];
    }
    printf("%lld\n", ans);
    return 0;
}
