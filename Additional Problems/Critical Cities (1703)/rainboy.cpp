/*
 https://cses.fi/problemset/task/1703
 Critical Cities
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N    100000
#define M    200000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct L {
    struct L *next;
    int j;
} aa[N];

int stack[N], dd[N], cnt, n;

void link(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

int dfs(int i, int d) {
    struct L *l;
    
    if (dd[i] < n)
        return 0;
    dd[i] = d;
    if (i == n - 1) {
        stack[cnt++] = i;
        return 1;
    }
    for (l = aa[i].next; l; l = l->next)
        if (dfs(l->j, d + 1)) {
            stack[cnt++] = i;
            return 1;
        }
    return 0;
}

int d_;

void dfs2(int i) {
    struct L *l;
    
    if (dd[i] < n) {
        if (d_ < dd[i])
            d_ = dd[i];
        return;
    }
    dd[i] = -1;
    for (l = aa[i].next; l; l = l->next)
        dfs2(l->j);
}

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static int cc[N];
    int m, h, i, j, k, tmp;
    
    init_rand();
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    for (i = 0; i < n; i++)
        dd[i] = n;
    dfs(0, 0);
    for (i = 0; i < n; i++)
        dd[i] = n;
    for (h = 0; h < cnt; h++) {
        i = stack[h];
        dd[i] = cnt - 1 - h;
    }
    d_ = 0;
    k = 0;
    for (h = cnt - 1; h >= 0; h--) {
        i = stack[h];
        if (dd[i] == d_)
            cc[k++] = i;
        dd[i] = n;
        dfs2(i);
    }
    for (j = 0; j < k; j++) {
        i = rand_(j + 1);
        tmp = cc[i], cc[i] = cc[j], cc[j] = tmp;
    }
    qsort(cc, k, sizeof *cc, compare);
    printf("%d\n", k);
    for (i = 0; i < k; i++)
        printf("%d ", cc[i] + 1);
    printf("\n");
    return 0;
}
