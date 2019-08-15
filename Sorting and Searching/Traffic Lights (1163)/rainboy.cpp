/*
 practice with Dukkha
 https://cses.fi/problemset/task/1163
 Traffic Lights
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N    200000

int pp[1 + N + 1], ii[1 + N + 1];
int gap[1 + N], dsu[1 + N];

int max(int a, int b) {
    return a > b ? a : b;
}

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return pp[i] - pp[j];
}

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

int join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) {
        if (dsu[i] > dsu[j]) {
            dsu[i] = j;
            gap[j] += gap[i];
            i = j;
        } else {
            if (dsu[i] == dsu[j])
                dsu[i]--;
            dsu[j] = i;
            gap[i] += gap[j];
        }
    }
    return gap[i];
}

int main() {
    static int aa[N];
    int n, x, i, ans;
    
    scanf("%d%d", &x, &n);
    pp[0] = 0;
    for (i = 1; i <= n; i++)
        scanf("%d", &pp[i]);
    pp[n + 1] = x;
    for (i = 0; i < 1 + n + 1; i++)
        ii[i] = i;
    qsort(ii, 1 + n + 1, sizeof *ii, compare);
    for (i = 0; i <= n; i++)
        gap[i] = pp[ii[i + 1]] - pp[ii[i]];
    memset(dsu, -1, sizeof dsu);
    for (i = 0; i < 1 + n + 1; i++)
        pp[ii[i]] = i;
    ans = 0;
    for (i = 0; i <= n; i++)
        ans = max(ans, gap[i]);
    aa[n - 1] = ans;
    for (i = n; i >= 2; i--)
        aa[i - 2] = ans = max(ans, join(pp[i] - 1, pp[i]));
    for (i = 0; i < n; i++)
        printf("%d ", aa[i]);
    printf("\n");
    return 0;
}
