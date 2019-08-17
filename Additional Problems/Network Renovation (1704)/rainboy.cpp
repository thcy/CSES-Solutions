/*
 https://cses.fi/problemset/task/1704
 Network Renovation
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000

struct L {
    struct L *next;
    int j;
} aa[N + 1];

int uu[N + 1], vv[N + 1];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

void dfs(int p, int i) {
    static int ii[N];
    struct L *l;
    int m, x, y, z, j;
    
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p)
            dfs(i, l->j);
    m = 0;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            if (uu[j] > 0)
                m++;
            if (vv[j] > 0)
                m++;
        }
    if (m == 0) {
        uu[i] = i;
        return;
    }
    x = 0, y = m - 1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p)
            if (vv[j] > 0) {
                ii[x++] = uu[j];
                ii[x++] = vv[j];
            } else
                ii[y--] = uu[j];
    uu[i] = ii[0];
    if (m % 2 == 0)
        vv[i] = ii[m - 1];
    for (z = 0; z < (m - 1) / 2; z++) {
        x = z * 2 + 1;
        y = z * 2 + 2;
        printf("%d %d\n", ii[x], ii[y]);
    }
}

int main() {
    int n, h, i, j, r, m;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j);
        link(i, j);
        link(j, i);
    }
    m = 0, r = 0;
    for (i = 1; i <= n; i++)
        if (!aa[i].next->next)
            m++;
        else
            r = i;
    printf("%d\n", (m + 1) / 2);
    dfs(-1, r);
    printf("%d %d\n", uu[r], vv[r] ? vv[r] : r);
    return 0;
}
