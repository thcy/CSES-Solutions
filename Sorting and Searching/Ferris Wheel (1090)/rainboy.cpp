/*
 https://cses.fi/problemset/task/1090
 Ferris Wheel
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
    static int pp[N];
    int n, x, i, j, ans;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &pp[i]);
    qsort(pp, n, sizeof *pp, compare);
    ans = n;
    for (i = 0, j = n - 1; i < j; i++) {
        while (j > i && pp[i] + pp[j] > x)
            j--;
        if (i < j)
            j--, ans--;
    }
    printf("%d\n", ans);
    return 0;
}
