/*
 https://cses.fi/problemset/task/1683
 Planets and Kingdoms
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N], bb[N];

int cc[N], qq[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next; bb[j].next = l++;
}

void dfs1(int i) {
    static int cnt;
    struct L *l;
    
    if (cc[i])
        return;
    cc[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        dfs1(l->j);
    qq[cnt++] = i;
}

void dfs2(int j, int c) {
    struct L *l;
    
    if (cc[j])
        return;
    cc[j] = c;
    for (l = bb[j].next; l; l = l->next)
        dfs2(l->j, c);
}

int main() {
    int n, m, h, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    for (i = 0; i < n; i++)
        dfs1(i);
    memset(cc, 0, n * sizeof *cc);
    c = 0;
    for (h = n - 1; h >= 0; h--) {
        i = qq[h];
        if (!cc[i])
            dfs2(i, ++c);
    }
    printf("%d\n", c);
    for (i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
