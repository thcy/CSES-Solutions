/*
 https://cses.fi/problemset/task/1077
 Sliding Cost
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000
#define M    (1 << 18)    /* M = pow2(ceil(log2(N))) */

int aa[N], bb[N], cnt[M * 2];
long long sum[M * 2];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

void update(int k, int l, int r, int i, int x) {
    cnt[k] += x;
    sum[k] += x * bb[i];
    if (r - l > 1) {
        int m = (l + r) / 2;
        
        if (i < m)
            update(k * 2 + 1, l, m, i, x);
        else
            update(k * 2 + 2, m, r, i, x);
    }
}

long long s;

int query(int k, int l, int r, int x) {
    int m, k1, k2;
    
    if (r - l == 1) {
        s += (long long) x * bb[l];
        return l;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    if (cnt[k1] >= x)
        return query(k1, l, m, x);
    else {
        s += sum[k1];
        return query(k2, m, r, x - cnt[k1]);
    }
}

int main() {
    static int ii[N];
    int n, m, k, h, i, j;
    long long ans;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare);
    m = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || aa[ii[i - 1]] != aa[ii[i]])
            bb[m++] = aa[ii[i]];
        aa[ii[i]] = m - 1;
    }
    h = (k + 1) / 2;
    for (i = 0; i < n; i++) {
        update(0, 0, m, aa[i], 1);
        if (i >= k)
            update(0, 0, m, aa[i - k], -1);
        if (i >= k - 1) {
            s = 0;
            j = query(0, 0, m, h);
            /* (h * bb[j] - s) + (sum[0] - s - (k - h) * bb[j]) */
            ans = sum[0] - s * 2 + (long long) (h * 2 - k) * bb[j];
            printf("%lld ", ans);
        }
    }
    printf("\n");
    return 0;
}
