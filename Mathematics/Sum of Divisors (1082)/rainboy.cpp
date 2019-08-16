/*
 https://cses.fi/problemset/task/1082
 Sum of Divisors
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

int main() {
    long long n, a, p, q, k, ans;
    
    scanf("%lld", &n);
    ans = 0;
    for (a = 1; a <= n / a; a++) {
        q = n / a;
        ans = (ans + a * q) % MD;
        if (a != q) {
            p = n / (a + 1);
            p %= MD;
            q %= MD;
            k = (q - p) * (q + p + 1) / 2 % MD;
            ans = (ans + k * a) % MD;
        }
    }
    if (ans < 0)
        ans += MD;
    printf("%lld\n", ans);
    return 0;
}
