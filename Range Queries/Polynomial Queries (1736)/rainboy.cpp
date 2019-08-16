/*
 https://cses.fi/problemset/task/1736
 Polynomial Queries
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define N_    (1 << 18)    /* N_ = pow2(ceil(log2(N))) */

int xx[N];
long long tr[N_ * 2], aa[N_ * 2], bb[N_ * 2];

void build(int k, int l, int r) {
    int m, k1, k2;
    
    if (r - l == 1) {
        tr[k] = xx[l];
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    build(k1, l, m);
    build(k2, m, r);
    tr[k] = tr[k1] + tr[k2];
}

long long sum(long long a, long long b, int n) {
    return n * (b * 2 + (n - 1) * a) / 2;
}

void update(int k, int l, int r, int ql, int qr, long long a, long long b) {
    int m, k1, k2;
    
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr) {
        long long b_ = b + (l - ql) * a;
        
        tr[k] += sum(a, b_, r - l);
        aa[k] += a;
        bb[k] += b_;
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    if (aa[k] || bb[k]) {
        update(k1, l, m, l, m, aa[k], bb[k]);
        update(k2, m, r, m, r, aa[k], bb[k] + (m - l) * aa[k]);
        aa[k] = bb[k] = 0;
    }
    update(k1, l, m, ql, qr, a, b);
    update(k2, m, r, ql, qr, a, b);
    tr[k] = tr[k1] + tr[k2];
}

long long query(int k, int l, int r, int ql, int qr) {
    int m, k1, k2;
    
    if (qr <= l || r <= ql)
        return 0;
    if (ql <= l && r <= qr)
        return tr[k];
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    if (aa[k] || bb[k]) {
        update(k1, l, m, l, m, aa[k], bb[k]);
        update(k2, m, r, m, r, aa[k], bb[k] + (m - l) * aa[k]);
        aa[k] = bb[k] = 0;
    }
    return query(k1, l, m, ql, qr) + query(k2, m, r, ql, qr);
}

int main() {
    int n, q, i;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &xx[i]);
    build(0, 0, n);
    while (q--) {
        int t, l, r;
        
        scanf("%d%d%d", &t, &l, &r), l--;
        if (t == 1)
            update(0, 0, n, l, r, 1, 1);
        else
            printf("%lld\n", query(0, 0, n, l, r));
    }
    return 0;
}
