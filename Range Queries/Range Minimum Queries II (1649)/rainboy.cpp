/*
 https://cses.fi/problemset/task/1649
 Range Minimum Queries II
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define N_    (1 << 18)    /* N_ = pow2(ceil(log2(N))) */
#define INF    0x3f3f3f3f

int tt[N_ * 2], aa[N];

void build(int k, int l, int r) {
    int m, k1, k2;
    
    if (r - l == 1) {
        tt[k] = aa[l];
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    build(k1, l, m);
    build(k2, m, r);
    tt[k] = tt[k1] < tt[k2] ? tt[k1] : tt[k2];
}

void update(int k, int l, int r, int i, int x) {
    int m, k1, k2;
    
    if (r - l == 1) {
        tt[k] = x;
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    if (i < m)
        update(k1, l, m, i, x);
    else
        update(k2, m, r, i, x);
    tt[k] = tt[k1] < tt[k2] ? tt[k1] : tt[k2];
}

int query(int k, int l, int r, int ql, int qr) {
    int m, q1, q2;
    
    if (qr <= l || r <= ql)
        return INF;
    if (ql <= l && r <= qr)
        return tt[k];
    m = (l + r) / 2;
    q1 = query(k * 2 + 1, l, m, ql, qr);
    q2 = query(k * 2 + 2, m, r, ql, qr);
    return q1 < q2 ? q1 : q2;
}

int main() {
    int n, q, i, j, a;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    build(0, 0, n);
    while (q--) {
        int    t;
        
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &i, &a), i--;
            update(0, 0, n, i, a);
        } else {
            scanf("%d%d", &i, &j), i--;
            printf("%d\n", query(0, 0, n, i, j));
        }
    }
    return 0;
}
