/*
 https://cses.fi/problemset/task/1666
 Building Roads
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000

int dsu[N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return;
    if (dsu[i] > dsu[j])
        dsu[i] = j;
    else {
        if (dsu[i] == dsu[j])
            dsu[i]--;
        dsu[j] = i;
    }
}

int main() {
    int n, m, h, i, j, k;
    
    scanf("%d%d", &n, &m);
    memset(dsu, -1, n * sizeof *dsu);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        join(i, j);
    }
    k = 0;
    for (i = 0; i < n; i++)
        if (dsu[i] < 0)
            dsu[k++] = i + 1;
    printf("%d\n", k - 1);
    for (h = 1; h < k; h++)
        printf("%d %d\n", dsu[h - 1], dsu[h]);
    return 0;
}
