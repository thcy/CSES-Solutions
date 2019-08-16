/*
 https://cses.fi/problemset/task/1131
 Tree Diameter
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int i_, d_;

void dfs(int p, int i, int d) {
    struct L *l;
    
    if (d_ < d)
        i_ = i, d_ = d;
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p)
            dfs(i, l->j, d + 1);
}

int main() {
    int n, h, i, j;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0, 0);
    dfs(-1, i_, 0);
    printf("%d\n", d_);
    return 0;
}
