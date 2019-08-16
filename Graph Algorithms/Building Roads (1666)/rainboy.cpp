/*
 https://cses.fi/problemset/task/1666
 Building Roads
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int cc[N];

void dfs(int i, int c) {
    struct L *l;
    
    cc[i] = c;
    for (l = aa[i].next; l; l = l->next)
        if (cc[l->j] == -1)
            dfs(l->j, c);
}

int main() {
    int n, m, h, i, j, k;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    memset(cc, -1, n * sizeof *cc);
    k = 0;
    for (i = 0; i < n; i++)
        if (cc[i] == -1)
            dfs(i, i);
    for (i = 0; i < n; i++)
        if (cc[i] == i)
            cc[k++] = i + 1;
    printf("%d\n", k - 1);
    for (h = 1; h < k; h++)
        printf("%d %d\n", cc[h - 1], cc[h]);
    return 0;
}
