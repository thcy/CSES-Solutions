/*
 https://cses.fi/problemset/task/1704
 Network Renovation
 upsolve with Dukkha
 https://cses.fi/problemset/hack/1704/entry/169196/ (Noam527)
 */
#include <stdio.h>

#define N    100000

struct L {
    struct L *next;
    int j;
} aa[N];

int ii[N], n;

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

void dfs(int p, int i) {
    struct L *l;
    
    if (!aa[i].next->next)
        ii[n++] = i;
    else
        for (l = aa[i].next; l; l = l->next)
            if (l->j != p)
                dfs(i, l->j);
}

int main() {
    int h, i, j, r, m, c;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
        link(j, i);
    }
    r = 0;
    while (!aa[r].next->next)
        r++;
    n = 0;
    dfs(-1, r);
    m = (n + 1) / 2, c = m - 1;
    printf("%d\n", m);
    for (h = 0; h < m - 1; h++)
        printf("%d %d\n", ii[h] + 1, ii[c * 2 - h] + 1);
    printf("%d %d\n", ii[c] + 1, ii[n - 1] + 1);
    return 0;
}
