/*
 https://cses.fi/problemset/task/1190
 Array Updates
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define M    (1 << 18)    /* M = pow2(ceil(log2(N))) */

long long max(long long a, long long b) { return a > b ? a : b; }

long long tt[M * 2], pp[M * 2], qq[M * 2], ss[M * 2];
int xx[N];

void init(int k, int x) {
    ss[k] = x;
    tt[k] = pp[k] = qq[k] = max(x, 0);
}

void pull(int k, int k1, int k2) {
    ss[k] = ss[k1] + ss[k2];
    pp[k] = max(pp[k1], ss[k1] + pp[k2]);
    qq[k] = max(qq[k2], ss[k2] + qq[k1]);
    tt[k] = max(max(tt[k1], tt[k2]), qq[k1] + pp[k2]);
}

void build(int k, int l, int r) {
    if (r - l == 1)
        init(k, xx[l]);
    else {
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        
        build(k1, l, m);
        build(k2, m, r);
        pull(k, k1, k2);
    }
}

void update(int k, int l, int r, int i, int x) {
    if (r - l == 1)
        init(k, x);
    else {
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        
        if (i < m)
            update(k1, l, m, i, x);
        else
            update(k2, m, r, i, x);
        pull(k, k1, k2);
    }
}

int main() {
    int n, m, i;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &xx[i]);
    build(0, 0, n);
    while (m--) {
        int i, x;
        
        scanf("%d%d", &i, &x), i--;
        update(0, 0, n, i, x);
        printf("%lld\n", tt[0]);
    }
    return 0;
}
