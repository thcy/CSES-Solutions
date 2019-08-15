/*
 https://cses.fi/problemset/task/1643
 Maximum Subarray Sum
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define INF    0x3f3f3f3f

int main() {
    static int xx[N];
    int n, i;
    long long max, sum;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &xx[i]);
    max = -INF;
    sum = 0;
    for (i = 0; i < n; i++)
        if (max < (sum = (sum > 0 ? sum : 0) + xx[i]))
            max = sum;
    printf("%lld\n", max);
    return 0;
}
