/*
 https://cses.fi/problemset/task/1757
 Course Schedule II
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

#define LT(u, v) ((u) > (v))

int pq[1 + N], iq[N], cnt;

int i2(int i) {
    return (i *= 2) > cnt ? 0 : i < cnt && LT(pq[i + 1], pq[i]) ? i + 1 : i;
}

void pq_up(int u) {
    int i, j;
    
    for (i = iq[u]; (j = i / 2) && LT(u, pq[j]); i = j)
        pq[iq[pq[j]] = i] = pq[j];
    pq[iq[u] = i] = u;
}

void pq_dn(int u) {
    int i, j;
    
    for (i = iq[u]; (j = i2(i)) && LT(pq[j], u); i = j)
        pq[iq[pq[j]] = i] = pq[j];
    pq[iq[u] = i] = u;
}

void pq_add(int u) {
    iq[u] = ++cnt;
    pq_up(u);
}

int pq_remove_first() {
    int u = pq[1], v = pq[cnt--];
    
    iq[v] = 1;
    pq_dn(v);
    return u;
}

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

int main() {
    static int dd[N], stack[N];
    int n, m, i, j, k;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(j, i), dd[i]++;
    }
    for (i = 0; i < n; i++)
        if (dd[i] == 0)
            pq_add(i);
    k = 0;
    while (cnt) {
        struct L *l;
        
        stack[k++] = i = pq_remove_first();
        for (l = aa[i].next; l; l = l->next)
            if (--dd[j = l->j] == 0)
                pq_add(l->j);
    }
    while (k--)
        printf("%d ", stack[k] + 1);
    printf("\n");
    return 0;
}
