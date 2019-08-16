/*
 Distinct Colors
 https://cses.fi/problemset/task/1139
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    500000

struct L {
    struct L *next;
    int j;
} aa[N];

int cc[N], ii[N], jj[N], ll[N], rr[N], tt[N];

int compare_c(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return cc[i] - cc[j];
}

int compare_l(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return ll[j] - ll[i];
}

void link(int i, int j) {
    static struct L l91[N * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

void dfs(int p, int i) {
    static int t;
    struct L *l;
    
    ll[i] = t++;
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p)
            dfs(i, l->j);
    rr[i] = t;
}

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int ans = 0;
    
    while (i >= 0) {
        ans += tt[i];
        i &= i + 1;
        i--;
    }
    return ans;
}

int main() {
    int n, m, h, i, i_, j, c;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &cc[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare_c);
    for (i = 0, m = 0; i < n; i++)
        cc[ii[i]] = i + 1 == n || cc[ii[i]] != cc[ii[i + 1]] ? m++ : m;
    for (h = 0; h < n - 1; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    dfs(-1, 0);
    qsort(ii, n, sizeof *ii, compare_l);
    for (i = 0; i < m; i++)
        jj[i] = -1;
    for (i_ = 0; i_ < n; i_++) {
        i = ii[i_], c = cc[i], j = jj[c];
        if (j != -1)
            update(ll[j], n, -1);
        update(ll[i], n, 1);
        jj[c] = i;
        cc[i] = query(rr[i] - 1);
    }
    for (i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
