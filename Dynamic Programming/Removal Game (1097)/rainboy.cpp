/*
 practice with Dukkha
 https://cses.fi/problemset/task/1097
 Removal Game
 */
#include <stdio.h>

#define N    5000

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    static long long aa[1 + N], dp[N];
    int n, i, j;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld", &aa[i]);
    for (i = 1; i <= n; i++)
        aa[i] += aa[i - 1];
    for (i = n - 1; i >= 0; i--) {
        dp[i] = aa[i + 1] - aa[i];
        for (j = i + 1; j < n; j++)
            dp[j] = aa[j + 1] - aa[i] - min(dp[j - 1], dp[j]);
    }
    printf("%lld\n", dp[n - 1]);
    return 0;
}
