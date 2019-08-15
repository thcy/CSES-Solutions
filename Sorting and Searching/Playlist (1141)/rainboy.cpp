/*
 https://cses.fi/problemset/task/1141
 Playlist
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

int aa[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] != aa[j] ? aa[i] - aa[j] : i - j;
}

int main() {
    static int ii[N], pp[N];
    int n, i, p, ans;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare);
    for (i = 0; i < n; i++)
        pp[ii[i]] = aa[ii[i - 1]] == aa[ii[i]] ? ii[i - 1] : -1;
    p = -1;
    ans = 0;
    for (i = 0; i < n; i++) {
        if (p < pp[i])
            p = pp[i];
        if (ans < i - p)
            ans = i - p;
    }
    printf("%d\n", ans);
    return 0;
}
