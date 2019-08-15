/*
 https://cses.fi/problemset/task/1076/
 Sliding Median
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000
#define M    524288    /* 2^19 */

int aa[N], bb[N], ii[N];
int tr[M];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

void update(int k, int l, int r, int i, int x) {
    tr[k] += x;
    if (r - l > 1) {
        int m = (l + r) / 2;
        
        if (i < m)
            update(k * 2 + 1, l, m, i, x);
        else
            update(k * 2 + 2, m, r, i, x);
    }
}

int query(int k, int l, int r, int n) {
    int m;
    
    if (r - l == 1)
        return l;
    m = (l + r) / 2;
    if (tr[k * 2 + 1] >= n)
        return query(k * 2 + 1, l, m, n);
    else
        return query(k * 2 + 2, m, r, n - tr[k * 2 + 1]);
}

int main() {
    int n, k, i, m;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare);
    for (i = 0, m = 0; i < n; i++) {
        if (i == 0 || aa[ii[i - 1]] != aa[ii[i]])
            bb[m++] = aa[ii[i]];
        aa[ii[i]] = m - 1;
    }
    for (i = 0; i < n; i++) {
        update(0, 0, m, aa[i], 1);
        if (i >= k)
            update(0, 0, m, aa[i - k], -1);
        if (i >= k - 1)
            printf("%d ", bb[query(0, 0, m, (k + 1) / 2)]);
    }
    printf("\n");
    return 0;
}
