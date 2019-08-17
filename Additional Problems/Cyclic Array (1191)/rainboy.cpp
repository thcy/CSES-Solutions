/*
 https://cses.fi/problemset/task/1191
 Cyclic Array
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000
#define L    18    /* L = floor(log2(N)) */

int main() {
    static long long aa[1 + N + N];
    static int pp[L + 1][1 + N + N];
    int n, i, j, k, l, ans, cnt;
    long long b;
    
    scanf("%d%lld", &n, &b);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &aa[i]);
        aa[i + n] = aa[i];
    }
    for (i = 1; i <= n + n; i++)
        aa[i] += aa[i - 1];
    l = 0;
    while (1 << (l + 1) <= n)
        l++;
    for (i = 1, j = 1; i <= n + n; i++) {
        while (j < n + n && aa[j] - aa[i - 1] <= b)
            j++;
        pp[0][i] = j;
    }
    for (k = 1; k <= l; k++)
        for (i = 1; i <= n + n; i++)
            pp[k][i] = pp[k - 1][pp[k - 1][i]];
    ans = n;
    for (i = 1; i <= n; i++) {
        cnt = 1;
        j = i;
        for (k = l; k >= 0; k--)
            if (pp[k][j] < i + n) {
                j = pp[k][j];
                cnt += 1 << k;
            }
        if (ans > cnt)
            ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
