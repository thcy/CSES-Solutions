/*
 https://cses.fi/problemset/task/1662
 Subarray Divisibility
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int kk[N];
    int n, i, a, a_;
    long long k, ans;
    
    scanf("%d", &n);
    a = 0;
    kk[a]++;
    for (i = 0; i < n; i++) {
        scanf("%d", &a_);
        if ((a = (a + a_) % n) < 0)
            a += n;
        kk[a]++;
    }
    ans = 0;
    for (a = 0; a < n; a++) {
        k = kk[a];
        ans += k * (k - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
