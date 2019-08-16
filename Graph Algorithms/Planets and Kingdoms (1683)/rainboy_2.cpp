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

int cc[N], qq[N], stack[M];

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
    int k, j;
    
    k = 0;
    stack[k++] = i;
    while (k > 0) {
        i = stack[k - 1];
        if (cc[i] == 0) {
            cc[i] = 1;
            for (l = aa[i].next; l; l = l->next)
                if (!cc[j = l->j])
                    stack[k++] = j;
        } else {
            k--;
            if (cc[i] == 1) {
                cc[i] = 2;
                qq[cnt++] = i;
            }
        }
    }
}

void dfs2(int j, int c) {
    struct L *l;
    int k, i;
    
    k = 0;
    stack[k++] = j; cc[j] = c;
    while (k > 0) {
        j = stack[--k];
        for (l = bb[j].next; l; l = l->next)
            if (!cc[i = l->j]) {
                stack[k++] = i; cc[i] = c;
            }
    }
}

int main() {
    int n, m, h, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    for (i = 0; i < n; i++)
        if (!cc[i])
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
