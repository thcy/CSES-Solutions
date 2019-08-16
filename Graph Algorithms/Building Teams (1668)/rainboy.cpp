/*
 https://cses.fi/problemset/task/1668
 Building Teams
 practice with Dukkha
 */
#include <stdio.h>

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

int dfs(int i, int c) {
    struct L *l;
    
    if (cc[i])
        return cc[i] == c;
    cc[i] = c;
    for (l = aa[i].next; l; l = l->next)
        if (!dfs(l->j, 3 - c))
            return 0;
    return 1;
}

int main() {
    int n, m, i, j;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    for (i = 0; i < n; i++)
        if (!cc[i] && !dfs(i, 1)) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    for (i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
