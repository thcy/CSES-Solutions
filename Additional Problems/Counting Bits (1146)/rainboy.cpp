/*
 https://cses.fi/problemset/task/1146
 Counting Bits
 */
#include <stdio.h>

int main() {
    long long n, ans;
    int i;
    
    scanf("%lld", &n);
    ans = 0;
    for (i = 0; 1LL << i <= n; i++) {
        ans += n >> (i + 1) << i;
        if (n & 1LL << i)
            ans += (n & (1LL << i) - 1) + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
