/*
 https://cses.fi/problemset/task/1682
 Flight Routes Check
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N], bb[N], *cc;

char visited[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next; bb[j].next = l++;
}

void dfs(int i) {
    struct L *l;
    
    if (visited[i])
        return;
    visited[i] = 1;
    for (l = cc[i].next; l; l = l->next)
        dfs(l->j);
}

int main() {
    int n, m, i, j;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    cc = aa;
    dfs(0);
    for (i = 0; i < n; i++)
        if (!visited[i]) {
            printf("NO\n");
            printf("1 %d\n", i + 1);
            return 0;
        }
    memset(visited, 0, n * sizeof *visited);
    cc = bb;
    dfs(0);
    for (i = 0; i < n; i++)
        if (!visited[i]) {
            printf("NO\n");
            printf("%d 1\n", i + 1);
            return 0;
        }
    printf("YES\n");
    return 0;
}
