/*
 https://cses.fi/problemset/task/1134
 Prüfer Code
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    500000

struct V {
    int i; /* for heap */
    int a;
} vv[N], *pq[1 + N];

int cnt;

#define LT(u, v) ((u)->a < (v)->a)

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
    static int aa[N], last[N];
    int n, i, a, b;
    
    scanf("%d", &n);
    for (i = 0; i < n - 2; i++)
        scanf("%d", &aa[i]), aa[i]--;
    memset(last, -1, sizeof last);
    for (i = 0; i < n - 2; i++)
        last[aa[i]] = i;
    for (a = 0; a < n; a++)
        vv[a].a = a;
    for (a = 0; a < n; a++)
        if (last[a] == -1)
            pq_add(&vv[a]);
    for (i = 0; i < n - 2; i++) {
        a = aa[i];
        b = pq_remove_first()->a;
        printf("%d %d\n", a + 1, b + 1);
        if (last[a] == i)
            pq_add(&vv[a]);
    }
    a = pq_remove_first()->a;
    b = pq_remove_first()->a;
    printf("%d %d\n", a + 1, b + 1);
    return 0;
}
