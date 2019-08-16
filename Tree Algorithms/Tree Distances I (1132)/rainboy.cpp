/*
 https://cses.fi/problemset/task/1132
 Tree Distances
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000

int max(int a, int b) { return a > b ? a : b; }

struct L {
    struct L *next;
    int j;
};

struct V {
    struct L adj;
    int d1, d2;
} vv[N];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = vv[i].adj.next; vv[i].adj.next = l++;
}

void dfs1(int p, int i) {
    struct V *u = &vv[i], *v;
    struct L *l;
    int d1, d2;
    
    d1 = d2 = -1;
    for (l = u->adj.next; l; l = l->next)
        if (l->j != p) {
            dfs1(i, l->j);
            v = &vv[l->j];
            if (d1 < v->d1)
                d2 = d1, d1 = v->d1;
            else if (d2 < v->d1)
                d2 = v->d1;
        }
    u->d1 = d1 + 1;
    u->d2 = d2 + 1;
}

void dfs2(int p, int i, int d_) {
    struct V *u = &vv[i], *v;
    struct L *l;
    int d1_, d2_;
    
    d1_ = max(d_, u->d1);
    d2_ = max(d_, u->d2);
    for (l = u->adj.next; l; l = l->next)
        if (l->j != p) {
            v = &vv[l->j];
            dfs2(i, l->j, (u->d1 == v->d1 + 1 ? d2_ : d1_) + 1);
        }
    u->d1 = d1_;
}

int main() {
    int n, h, i, j;
    
    scanf("%d", &n);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs1(-1, 0);
    dfs2(-1, 0, 0);
    for (i = 0; i < n; i++)
        printf("%d ", vv[i].d1);
    printf("\n");
    return 0;
}
