/*
 https://cses.fi/problemset/task/1665
 Coding Company
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    100
#define Y    5000
#define MD    1000000007

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ib - ia;
}

int main() {
    static int aa[N], dp[N / 2 + 1][Y + 1], dq[N / 2 + 1][Y + 1];
    int n, h, x, i, t, a, b, p, sum;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    qsort(aa, n, sizeof *aa, compare);
    h = n / 2;
    dp[0][0] = 1;
    for (i = 0; i < n; i++) {
        for (t = 0; t <= h; t++)
            for (b = 0; b <= Y; b++)
                dq[t][b] = 0;
        a = aa[i];
        for (t = 0; t <= h; t++)
            for (b = 0; b <= Y; b++) {
                p = dp[t][b];
                if (p == 0)
                    continue;
                if (t + 1 <= h)
                    dq[t + 1][b + a] = (dq[t + 1][b + a] + p) % MD;
                if (t - 1 >= 0)
                    dq[t - 1][b - a] = (dq[t - 1][b - a] + (long long) p * t) % MD;
                dq[t][b] = (dq[t][b] + (long long) p * (t + 1)) % MD;
            }
        for (t = 0; t <= h; t++)
            for (b = 0; b <= Y; b++)
                dp[t][b] = dq[t][b];
    }
    sum = 0;
    for (b = 0; b <= x; b++)
        sum = (sum + dp[0][b]) % MD;
    printf("%d\n", sum);
    return 0;
}
