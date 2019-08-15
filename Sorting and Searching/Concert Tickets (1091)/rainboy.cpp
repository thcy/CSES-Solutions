/*
 https://cses.fi/problemset/task/1091
 Concert Tickets
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N    200000

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int dsu[N], ll[N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return;
    if (dsu[i] > dsu[j]) {
        dsu[i] = j;
        ll[j] = ll[i];
    } else {
        if (dsu[i] == dsu[j])
            dsu[i]--;
        dsu[j] = i;
    }
}

int main() {
    static int aa[N];
    static char removed[N];
    int n, m, i;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    qsort(aa, n, sizeof *aa, compare);
    for (i = 0; i < n; i++)
        ll[i] = i;
    memset(dsu, -1, sizeof dsu);
    while (m--) {
        int a, lower, upper;
        
        scanf("%d", &a);
        lower = -1, upper = n;
        while (upper - lower > 1) {
            i = (lower + upper) / 2;
            if (aa[i] <= a)
                lower = i;
            else
                upper = i;
        }
        if (lower == -1) {
            printf("-1\n");
            continue;
        }
        i = lower;
        if (i == -1) {
            printf("-1\n");
            continue;
        }
        if (removed[i])
            i = ll[find(i)] - 1;
        if (i == -1) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", aa[i]);
        removed[i] = 1;
        if (i - 1 >= 0 && removed[i - 1])
            join(i - 1, i);
        if (i + 1 < n && removed[i + 1])
            join(i, i + 1);
    }
    return 0;
}
