/*
 https://cses.fi/problemset/task/1647
 Range Minimum Queries I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define N_    (1 << 18)    /* N_ = pow2(ceil(log2(N))) */
#define INF    0x3f3f3f3f

int tt[N_ * 2];

void build(int *aa, int k, int l, int r) {
    int m, k1, k2;
    
    if (r - l == 1) {
        tt[k] = aa[l];
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    build(aa, k1, l, m);
    build(aa, k2, m, r);
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
    static int aa[N];
    int n, q, i, j;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    build(aa, 0, 0, n);
    while (q--) {
        scanf("%d%d", &i, &j), i--;
        printf("%d\n", query(0, 0, n, i, j));
    }
    return 0;
}
