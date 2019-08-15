/*
 https://cses.fi/problemset/task/1620
 Factory Machines
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int aa[N];
    int n, k, i;
    long long lower, upper, t, cnt;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    lower = 0, upper = 2e18;
    while (upper - lower > 1) {
        t = (lower + upper) / 2;
        cnt = 0;
        for (i = 0; i < n; i++)
            if ((cnt += t / aa[i]) >= k)
                break;
        if (cnt >= k)
            upper = t;
        else
            lower = t;
    }
    printf("%lld\n", upper);
    return 0;
}
