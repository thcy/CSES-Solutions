/*
 https://cses.fi/problemset/task/1687
 Company Queries I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define Q    200000

struct L {
    struct L *next;
    int j;
} aa[N], hh[N];

int kk[Q], bb[Q];

void link(int i, int j) {
    static struct L l91[N], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

void link_(int i, int h) {
    static struct L l91[Q], *l = l91;
    
    l->j = h;
    l->next = hh[i].next, hh[i].next = l++;
}

int stack[N], cnt;

void dfs(int i) {
    struct L *l;
    
    for (l = hh[i].next; l; l = l->next) {
        int h = l->j, k = kk[h];
        
        bb[h] = k <= cnt ? stack[cnt - k] + 1 : -1;
    }
    stack[cnt++] = i;
    for (l = aa[i].next; l; l = l->next)
        dfs(l->j);
    cnt--;
}

int main() {
    int n, q, p, h, i;
    
    scanf("%d%d", &n, &q);
    for (i = 1; i < n; i++) {
        scanf("%d", &p), p--;
        link(p, i);
    }
    for (h = 0; h < q; h++) {
        scanf("%d%d", &i, &kk[h]), i--;
        link_(i, h);
    }
    dfs(0);
    for (h = 0; h < q; h++)
        printf("%d\n", bb[h]);
    return 0;
}
