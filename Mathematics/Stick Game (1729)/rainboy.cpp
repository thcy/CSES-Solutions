/*
 https://cses.fi/problemset/task/1729
 Stick Game
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N    1000000
#define K    100

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static int pp[K];
    static char aa[N + 2];
    int n, k, h, i, j;
    
    scanf("%d%d", &n, &k);
    for (h = 0; h < k; h++)
        scanf("%d", &pp[h]);
    qsort(pp, k, sizeof *pp, compare);
    memset(aa, 'L', (n + 1) * sizeof *aa);
    for (i = 0; i < n; i++)
        if (aa[i] == 'L')
            for (h = 0; h < k && (j = i + pp[h]) <= n; h++)
                aa[j] = 'W';
    printf("%s\n", aa + 1);
    return 0;
}
