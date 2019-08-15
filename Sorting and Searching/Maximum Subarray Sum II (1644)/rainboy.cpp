/*
 https://cses.fi/problemset/task/1644
 Maximum Subarray Sum II
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static long long xx[N + 1];
    static int qq[N];
    int n, a, b, i, head, cnt;
    long long x, x_;
    
    scanf("%d%d%d", &n, &a, &b);
    x = 0;
    for (i = 1; i <= n; i++)
        scanf("%lld", &xx[i]), xx[i] = x += xx[i];
    head = cnt = 0;
    x = -3e14;
    for (i = a; i <= n; i++) {
        while (cnt && xx[qq[head + cnt - 1]] >= xx[i - a])
            cnt--;
        qq[head + cnt++] = i - a;
        if (x < (x_ = xx[i] - xx[qq[head]]))
            x = x_;
        if (qq[head] == i - b)
            head++, cnt--;
    }
    printf("%lld\n", x);
    return 0;
}
