/*
 https://cses.fi/problemset/task/1678
 Round Trip II
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
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int pp[N], qq[N + 1], cnt;

int dfs(int i) {
    static char instack[N];
    struct L *l;
    int j;
    
    instack[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        if (pp[j = l->j] == -1) {
            pp[j] = i;
            if (dfs(j))
                return 1;
        } else if (instack[j]) {
            cnt = 0;
            qq[cnt++] = j;
            while (i != j) {
                qq[cnt++] = i;
                i = pp[i];
            }
            qq[cnt++] = j;
            return 1;
        }
    instack[i] = 0;
    return 0;
}

int main() {
    int n, m, i, j;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    memset(pp, -1, n * sizeof *pp);
    for (i = 0; i < n; i++)
        if (pp[i] == -1) {
            pp[i] = i;
            if (dfs(i))
                break;
        }
    if (cnt == 0)
        printf("IMPOSSIBLE\n");
    else {
        printf("%d\n", cnt);
        while (cnt--)
            printf("%d ", qq[cnt] + 1);
        printf("\n");
    }
    return 0;
}
