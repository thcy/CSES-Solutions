/*
 https://cses.fi/problemset/task/1641
 Sum of Three Values
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    5000

int aa[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

int main() {
    static int ii[N];
    int n, x, i, j, k;
    long long a, b;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare);
    for (k = 2; k < n; k++)
        for (i = 0, j = k - 1; i < j; i++) {
            b = aa[ii[k]];
            while (i < j && (a = aa[ii[i]] + aa[ii[j]] + b) > x)
                j--;
            if (i < j && a == x) {
                printf("%d %d %d\n", ii[i] + 1, ii[j] + 1, ii[k] + 1);
                return 0;
            }
        }
    printf("IMPOSSIBLE\n");
    return 0;
}
