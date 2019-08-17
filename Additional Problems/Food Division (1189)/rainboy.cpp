/*
 https://cses.fi/problemset/task/1189
 Food Division
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    500000

int compare(const void *a, const void *b) {
    long long la = *(long long *) a;
    long long lb = *(long long *) b;
    
    return la == lb ? 0 : la < lb ? -1 : 1;
}

int main() {
    static long long aa[N];
    int n, i, x;
    long long med, ans;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        aa[i] = x;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        aa[i] -= x;
    }
    for (i = 1; i < n; i++)
        aa[i] += aa[i - 1];
    qsort(aa, n, sizeof *aa, compare);
    med = aa[n / 2];
    ans = 0;
    for (i = 0; i < n; i++)
        ans += aa[i] > med ? aa[i] - med : med - aa[i];
    printf("%lld\n", ans);
    return 0;
}
