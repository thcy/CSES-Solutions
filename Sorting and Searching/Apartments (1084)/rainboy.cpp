/*
 https://cses.fi/problemset/task/1084
 Apartments
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000
#define M    200000

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static int aa[N], bb[M];
    int n, m, k, i, j, cnt;
    
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    for (j = 0; j < m; j++)
        scanf("%d", &bb[j]);
    qsort(aa, n, sizeof *aa, compare);
    qsort(bb, m, sizeof *bb, compare);
    cnt = 0;
    for (i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && bb[j] < aa[i] - k)
            j++;
        if (j < m && bb[j] <= aa[i] + k)
            j++, cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
