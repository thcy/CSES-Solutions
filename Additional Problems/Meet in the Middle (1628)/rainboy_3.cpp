/*
 https://cses.fi/problemset/task/1628
 Meet in the Middle
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    40
#define N_    (1 << (N / 2))

void build(int *aa, long long *ss, int l, int r) {
    static long long tt[N_];
    int a, h, k, p, p_, q, q_;
    
    ss[0] = 0;
    for (k = 1; l < r; l++, k <<= 1) {
        a = aa[l];
        for (h = 0; h < k; h++) {
            tt[h] = ss[h];
            tt[h + k] = ss[h] + a;
        }
        p = 0, q = k, p_ = k, q_ = k + k, h = 0;
        while (p < p_ && q < q_)
            if (tt[p] < tt[q])
                ss[h++] = tt[p++];
            else
                ss[h++] = tt[q++];
        while (p < p_)
            ss[h++] = tt[p++];
        while (q < q_)
            ss[h++] = tt[q++];
    }
}

int main() {
    static int aa[N];
    static long long a0[N_], a1[N_];
    int n, n0, n1, k0, k1, x, i, p, q;
    long long y, ans;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    k0 = n / 2, k1 = n - k0, n0 = 1 << k0, n1 = 1 << k1;
    build(aa, a0, 0, k0);
    build(aa, a1, k0, n);
    ans = 0;
    for (i = 0, p = n1 - 1, q = p; i < n0; i++) {
        while (q >= 0 && (y = a0[i] + a1[q]) > x)
            q--;
        if (q < 0)
            break;
        if (y == x) {
            if (p > q)
                p = q;
            while (p > 0 && a1[p - 1] == a1[q])
                p--;
            ans += q - p + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
