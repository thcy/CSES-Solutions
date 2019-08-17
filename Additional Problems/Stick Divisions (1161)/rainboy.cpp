/*
 https://cses.fi/problemset/task/1161
 Stick Divisions
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

struct V {
    int i; /* for heap */
    int x;
} vv[N], *pq[1 + N];

int cnt;

#define LT(u, v) ((u)->x < (v)->x)

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

int main() {
    int x, n, i;
    long long ans;
    
    scanf("%d%d", &x, &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        vv[i].x = x;
        pq_add(&vv[i]);
    }
    ans = 0;
    while (--n) {
        struct V *u = pq_remove_first(), *v = pq_remove_first();
        
        ans += u->x += v->x;
        pq_add(u);
    }
    printf("%lld\n", ans);
    return 0;
}
