/*
 https://cses.fi/problemset/task/1143
 Hotels
 */
#include <stdio.h>

#define N    200000
#define N_    (1 << 18)    /* pow2(ceil(log2(N))) */

int tr[N_ * 2], hh[N];

void build(int k, int l, int r) {
    if (r - l == 1)
        tr[k] = hh[l];
    else {
        int    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = tr[k1] > tr[k2] ? tr[k1] : tr[k2];
    }
}

int update(int k, int l, int r, int x) {
    int    m, k1, k2, i;
    
    if (r - l == 1) {
        tr[k] -= x;
        return l;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    i = tr[k1] >= x ? update(k1, l, m, x) : update(k2, m, r, x);
    tr[k] = tr[k1] > tr[k2] ? tr[k1] : tr[k2];
    return i;
}

int main() {
    int n, m, i;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &hh[i]);
    build(0, 0, n);
    while (m--) {
        int x, i;
        
        scanf("%d", &x);
        i = tr[0] >= x ? update(0, 0, n, x) + 1 : 0;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
