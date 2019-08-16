/*
 https://cses.fi/problemset/task/1735
 Range Updates and Sums
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define N_    (1 << 18)    /* N_ = pow2(ceil(log2(N))) */

int aa[N];
long long tr[N_ * 2], inc[N_ * 2], set[N_ * 2];

void build(int k, int l, int r) {
    int m, k1, k2;
    
    if (r - l == 1) {
        tr[k] = aa[l];
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    build(k1, l, m);
    build(k2, m, r);
    tr[k] = tr[k1] + tr[k2];
}

void update(int k, int l, int r, int ql, int qr, int t, long long x);

void push(int k, int l, int r) {
    int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    
    if (set[k]) {
        update(k1, l, m, l, m, 2, set[k]);
        update(k2, m, r, m, r, 2, set[k]);
        set[k] = 0;
    } else if (inc[k]) {
        update(k1, l, m, l, m, 1, inc[k]);
        update(k2, m, r, m, r, 1, inc[k]);
        inc[k] = 0;
    }
}

void update(int k, int l, int r, int ql, int qr, int t, long long x) {
    int m, k1, k2;
    
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr) {
        if (t == 1) {
            tr[k] += (r - l) * x;
            if (set[k] == 0)
                inc[k] += x;
            else
                set[k] += x;
        } else {
            tr[k] = (r - l) * x;
            set[k] = x;
            inc[k] = 0;
        }
        return;
    }
    push(k, l, r);
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    update(k1, l, m, ql, qr, t, x);
    update(k2, m, r, ql, qr, t, x);
    tr[k] = tr[k1] + tr[k2];
}

long long query(int k, int l, int r, int ql, int qr) {
    int m, k1, k2;
    
    if (qr <= l || r <= ql)
        return 0;
    if (ql <= l && r <= qr)
        return tr[k];
    push(k, l, r);
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    return query(k1, l, m, ql, qr) + query(k2, m, r, ql, qr);
}

int main() {
    int n, q, i;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    build(0, 0, n);
    while (q--) {
        int t, l, r, x;
        
        scanf("%d%d%d", &t, &l, &r), l--;
        if (t != 3) {
            scanf("%d", &x);
            update(0, 0, n, l, r, t, x);
        } else
            printf("%lld\n", query(0, 0, n, l, r));
    }
    return 0;
}
