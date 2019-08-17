/*
 https://cses.fi/problemset/task/1752
 Creating Offices
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define INF    0x3f3f3f3f

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

char used[N];
int cc[N], dd[N], dd_[N], lambda;

void dfs(int p, int i, int d) {
    struct L *l;
    int j, c, c_, d_;
    
    dd[i] = d;
    d_ = INF, c_ = -1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            dfs(i, j, d + 1);
            if (d_ > dd_[j])
                d_ = dd_[j];
            c = cc[j];
            if (c == -1)
                continue;
            if ((dd[c] - d) * 2 >= lambda) {
                used[c] = 1;
                if (d_ > dd[c])
                    d_ = dd[c];
            } else if (c_ == -1 || dd[c_] < dd[c])
                c_ = c;
        }
    if (c_ != -1 && dd[c_] - d + d_ - d < lambda)
        c_ = -1;
    if (c_ == -1 && d_ - d >= lambda)
        c_ = i;
    dd_[i] = d_;
    cc[i] = c_;
}

int main() {
    int n, h, i, j, k;
    
    scanf("%d%d", &n, &lambda);
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0, 0);
    if (cc[0] != -1)
        used[cc[0]] = 1;
    k = 0;
    for (i = 0; i < n; i++)
        if (used[i])
            k++;
    printf("%d\n", k);
    for (i = 0; i < n; i++)
        if (used[i])
            printf("%d ", i + 1);
    printf("\n");
    return 0;
}
