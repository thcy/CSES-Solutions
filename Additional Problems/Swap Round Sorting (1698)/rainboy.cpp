/*
 https://cses.fi/problemset/task/1698
 Swap Round Sorting
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int aa[N], s1[N], s2[N], qq[N];
    int n, i, j, cnt, k1, k2, u, v;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]), aa[i]--;
    k1 = k2 = 0;
    for (i = 0; i < n; i++) {
        if (aa[i] < 0 || aa[i] == i)
            continue;
        cnt = 0;
        for (j = i; aa[j] >= 0; aa[j] = -aa[j], j = -aa[j])
            qq[cnt++] = j;
        for (u = 0, v = cnt - 2; u < v; u++, v--) {
            s1[k1++] = qq[u];
            s1[k1++] = qq[v];
        }
        for (u = 0, v = cnt - 1; u < v; u++, v--) {
            s2[k2++] = qq[u];
            s2[k2++] = qq[v];
        }
    }
    printf("%d\n", k2 == 0 ? 0 : k1 == 0 ? 1 : 2);
    if (k1) {
        printf("%d\n", k1 / 2);
        while (k1) {
            printf("%d %d\n", s1[k1 - 1] + 1, s1[k1 - 2] + 1);
            k1 -= 2;
        }
    }
    if (k2) {
        printf("%d\n", k2 / 2);
        while (k2) {
            printf("%d %d\n", s2[k2 - 1] + 1, s2[k2 - 2] + 1);
            k2 -= 2;
        }
    }
    return 0;
}
