/*
 https://cses.fi/problemset/task/1195
 Flight Discount
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000
#define INF    0x3f3f3f3f3f3f3f3f

struct L {
    struct L *next;
    struct E *e;
};

struct E {
    int j, c;
};

struct V {
    int i;    /* for heap */
    struct L adj;
    long long c;
} vv[N * 2], *pq[1 + N * 2];

int cnt;

#define LT(u, v) ((u)->c < (v)->c)

int i2(int i) {
    return (i *= 2) > cnt ? 0 : i < cnt && LT(pq[i + 1], pq[i]) ? i + 1 : i;
}

void pq_up(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i / 2) && LT(u, pq[j]); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_dn(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i2(i)) && LT(pq[j], u); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_add(struct V *u) {
    u->i = ++cnt;
    pq_up(u);
}

struct V *pq_remove_first() {
    struct V *u = pq[1], *v = pq[cnt--];
    
    v->i = 1;
    pq_dn(v);
    return u;
}

void link(int i, int j, int c) {
    static struct E e91[M * 3], *e = e91;
    static struct L l91[M * 3], *l = l91;
    
    e->j = j, e->c = c;
    l->e = e++;
    l->next = vv[i].adj.next; vv[i].adj.next = l++;
}

int main() {
    int n, m, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        link(i * 2 + 0, j * 2 + 0, c);
        link(i * 2 + 0, j * 2 + 1, c / 2);
        link(i * 2 + 1, j * 2 + 1, c);
    }
    for (i = 2; i < n * 2; i++)
        vv[i].c = INF;
    pq_add(&vv[0]);
    pq_add(&vv[1]);
    while (cnt) {
        struct V *u = pq_remove_first();
        struct L *l;
        
        if (u == &vv[n * 2 - 1]) {
            printf("%lld\n", u->c);
            return 0;
        }
        for (l = u->adj.next; l; l = l->next) {
            struct E *e = l->e;
            struct V *v = &vv[e->j];
            long long c = u->c + e->c;
            
            if (v->c == INF) {
                v->c = c;
                pq_add(v);
            } else if (v->c > c) {
                v->c = c;
                pq_up(v);
            }
        }
    }
    return 0;
}
