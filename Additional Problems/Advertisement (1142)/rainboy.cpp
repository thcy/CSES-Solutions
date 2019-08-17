/*
 https://cses.fi/problemset/task/1142
 Advertisement
 */
#include <stdio.h>

#define N    500000

int main() {
    static int aa[1 + N + 1], stack[1 + N], ll[1 + N], rr[1 + N];
    int n, i, cnt;
    long long ans;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &aa[i]);
    cnt = 0;
    stack[cnt++] = 0;
    for (i = 1; i <= n; i++) {
        while (cnt && aa[stack[cnt - 1]] >= aa[i])
            cnt--;
        ll[i] = stack[cnt - 1];
        stack[cnt++] = i;
    }
    cnt = 0;
    stack[cnt++] = n + 1;
    for (i = n; i >= 1; i--) {
        while (cnt && aa[stack[cnt - 1]] >= aa[i])
            cnt--;
        rr[i] = stack[cnt - 1];
        stack[cnt++] = i;
    }
    ans = 0;
    for (i = 1; i <= n; i++) {
        long long x = (long long) (rr[i] - ll[i] - 1) * aa[i];
        
        if (ans < x)
            ans = x;
    }
    printf("%lld\n", ans);
    return 0;
}
