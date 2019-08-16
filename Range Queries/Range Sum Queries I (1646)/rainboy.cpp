/*
 https://cses.fi/problemset/task/1646
 Range Sum Queries I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static long long aa[N];
    int n, q, i, j;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%lld", &aa[i]);
    for (i = 1; i < n; i++)
        aa[i] += aa[i - 1];
    while (q--) {
        scanf("%d%d", &i, &j), i--, j--;
        printf("%lld\n", aa[j] - (i == 0 ? 0 : aa[i - 1]));
    }
    return 0;
}
