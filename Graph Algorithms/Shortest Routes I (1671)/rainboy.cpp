/*
 https://cses.fi/problemset/task/1671
 Shortest Routes I
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000
#define INF    0x3f3f3f3f3f3f3f3fLL

struct L {
    struct L *next;
    int j, c;
} aa[N];

void link(int i, int j, int c) {
    static struct L l91[M], *l = l91;
    
    l->j = j, l->c = c;
    l->next = aa[i].next, aa[i].next = l++;
}

long long dd[N];
int pq[1 + N], iq[N], cnt;

#define LT(u, v)    (dd[u] < dd[v])

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

int main() {
    int n, m, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        link(i, j, c);
    }
    memset(dd, 0x3f, sizeof dd);
    dd[0] = 0;
    pq_add(0);
    while (cnt) {
        struct L *l;
        
        i = pq_remove_first();
        for (l = aa[i].next; l; l = l->next) {
            long long d = dd[i] + l->c;
            
            if (dd[l->j] == INF) {
                dd[l->j] = d;
                pq_add(l->j);
            } else if (dd[l->j] > d) {
                dd[l->j] = d;
                pq_up(l->j);
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%lld ", dd[i]);
    printf("\n");
    return 0;
}
