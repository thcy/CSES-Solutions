/*
 https://cses.fi/problemset/task/1130
 Tree Matching
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000

struct L {
    struct L *next;
    int j;
} aa[N];

int dp[N], dp1[N];

void link(int i, int j) {
    static struct L ll_[N * 2], *l = ll_;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

void dfs(int p, int i) {
    struct L *l;
    int x0, x1;
    
    x0 = 0, x1 = 1;
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p) {
            dfs(i, l->j);
            x0 += dp1[l->j];
            x1 += dp[l->j];
        }
    dp1[i] = x1;
    dp[i] = x0 < x1 ? x0 : x1;
}

int main() {
    int n, h, i, j;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0);
    printf("%d\n", dp[0]);
    return 0;
}
