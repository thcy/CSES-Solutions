/*
 https://cses.fi/problemset/task/1699
 Flight Route Requests
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N], bb[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next, bb[j].next = l++;
}

int dd[N];
char visited[N];
int ii[N], n_;

void dfs(int i) {
    struct L *l;
    
    if (visited[i])
        return;
    visited[i] = 1;
    ii[n_++] = i;
    for (l = aa[i].next; l; l = l->next)
        dfs(l->j);
    for (l = bb[i].next; l; l = l->next)
        dfs(l->j);
}

int acyclic() {
    static int qq[N];
    int head, cnt, h, i, j;
    
    head = cnt = 0;
    for (h = 0; h < n_; h++)
        if (dd[i = ii[h]] == 0)
            qq[head + cnt++] = i;
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        for (l = aa[i].next; l; l = l->next)
            if (--dd[j = l->j] == 0)
                qq[head + cnt++] = j;
    }
    return head == n_;
}

int main() {
    int n, m, i, j, ans;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        if (i == j)
            continue;
        link(i, j), dd[j]++;
    }
    ans = n;
    for (i = 0; i < n; i++)
        if (!visited[i]) {
            n_ = 0;
            dfs(i);
            if (acyclic())
                ans--;
        }
    printf("%d\n", ans);
    return 0;
}
