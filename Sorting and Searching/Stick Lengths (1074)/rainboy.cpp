/*
 https://cses.fi/problemset/task/1074
 Sticks
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static int aa[N];
    int n, i, a;
    long long ans;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    qsort(aa, n, sizeof *aa, compare);
    a = aa[n / 2];
    ans = 0;
    for (i = 0; i < n; i++)
        ans += abs(aa[i] - a);
    printf("%lld\n", ans);
    return 0;
}
