/*
 practice with Dukkha
 https://cses.fi/problemset/task/1188
 Bit Inversions
 */
#include <stdio.h>
#include <string.h>

#define N    200000
#define M    (1 << 18)    /* M = pow2(ceil(log2(N))) */

int max(int a, int b) { return a > b ? a : b; }

char cc[N + 1];
int pp[M * 2], qq[M * 2], tr[M * 2];

void pull(int k, int l, int r) {
    int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    
    pp[k] = pp[k1];
    if (pp[k1] == m - l && cc[l] == cc[m])
        pp[k] += pp[k2];
    qq[k] = qq[k2];
    if (qq[k2] == r - m && cc[r - 1] == cc[m - 1])
        qq[k] += qq[k1];
    tr[k] = max(tr[k1], tr[k2]);
    if (cc[m - 1] == cc[m])
        tr[k] = max(tr[k], qq[k1] + pp[k2]);
}

void build(int k, int l, int r) {
    int m;
    
    if (r - l == 1) {
        pp[k] = qq[k] = tr[k] = 1;
        return;
    }
    m = (l + r) / 2;
    build(k * 2 + 1, l, m);
    build(k * 2 + 2, m, r);
    pull(k, l, r);
}

void update(int k, int l, int r, int i) {
    int m;
    
    if (r - l == 1) {
        cc[i] = cc[i] == '0' ? '1' : '0';
        return;
    }
    m = (l + r) / 2;
    if (i < m)
        update(k * 2 + 1, l, m, i);
    else
        update(k * 2 + 2, m, r, i);
    pull(k, l, r);
}

int main() {
    int n, m;
    
    scanf("%s%d", cc, &m);
    n = strlen(cc);
    build(0, 0, n);
    while (m--) {
        int i;
        
        scanf("%d", &i), i--;
        update(0, 0, n, i);
        printf("%d ", tr[0]);
    }
    printf("\n");
    return 0;
}
