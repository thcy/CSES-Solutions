/*
 https://cses.fi/problemset/task/1133
 Tree Distances II
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000

int n;

struct L {
    struct L *next;
    int j;
} aa[N];

int kk[N];
long long dd[N];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

void dfs1(int p, int i) {
    struct L *l;
    long long d;
    int j, k;
    
    d = 0;
    k = 0;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            dfs1(i, j);
            d += dd[j];
            k += kk[j];
        }
    dd[i] = d + k;
    kk[i] = k + 1;
}

void dfs2(int p, int i, long long d) {
    struct L *l;
    int j;
    
    dd[i] = d;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p)
            dfs2(i, j, dd[i] - kk[j] + n - kk[j]);
}

int main() {
    int h, i, j;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs1(-1, 0);
    dfs2(-1, 0, dd[0]);
    for (i = 0; i < n; i++)
        printf("%lld ", dd[i]);
    printf("\n");
    return 0;
}
