/*
 https://cses.fi/problemset/task/1746
 Array Description
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define M    100
#define MD    1000000007

int main() {
    static int dp_[M + 2], dq_[M + 2];
    int *dp = dp_, *dq = dq_, *tmp, n, m, x;
    long long ans;
    
    scanf("%d%d", &n, &m);
    scanf("%d", &x);
    if (x == 0)
        for (x = 1; x <= m; x++)
            dp[x] = 1;
    else
        dp[x] = 1;
    while (--n) {
        scanf("%d", &x);
        if (x == 0)
            for (x = 1; x <= m; x++)
                dq[x] = ((long long) dp[x - 1] + dp[x] + dp[x + 1]) % MD;
        else {
            memset(dq, 0, (m + 2) * sizeof *dq);
            dq[x] = ((long long) dp[x - 1] + dp[x] + dp[x + 1]) % MD;
        }
        tmp = dp, dp = dq, dq = tmp;
    }
    ans = 0;
    for (x = 1; x <= m; x++)
        ans += dp[x];
    printf("%lld\n", ans % MD);
    return 0;
}
