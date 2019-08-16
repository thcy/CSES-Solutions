/*
 https://cses.fi/problemset/task/1737
 Range Queries and Copies
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define Q    200000
#define LN    18    /* LN = ceil(log2(N)) */

struct T {
    struct T *l, *r;
    long long x;
} *tt[Q];

struct T *new_T() {
    static struct T t91[N * 2 + Q * (LN + 1)], *t = t91;
    
    return t++;
}

int aa[N];

struct T *build(int l, int r) {
    struct T *t = new_T();
    
    if (r - l == 1)
        t->x = aa[l];
    else {
        int m = (l + r) / 2;
        
        t->l = build(l, m);
        t->r = build(m, r);
        t->x = t->l->x + t->r->x;
    }
    return t;
}

struct T *update(struct T *t, int l, int r, int i, int x) {
    struct T *t_ = new_T();
    
    if (r - l == 1)
        t_->x = x;
    else {
        int m = (l + r) / 2;
        
        if (i < m) {
            t_->l = update(t->l, l, m, i, x);
            t_->r = t->r;
        } else {
            t_->l = t->l;
            t_->r = update(t->r, m, r, i, x);
        }
        t_->x = t_->l->x + t_->r->x;
    }
    return t_;
}

long long query(struct T *t, int l, int r, int ql, int qr) {
    int m;
    
    if (qr <= l || r <= ql || t == NULL)
        return 0;
    if (ql <= l && r <= qr)
        return t->x;
    m = (l + r) / 2;
    return query(t->l, l, m, ql, qr) + query(t->r, m, r, ql, qr);
}

int main() {
    int n, q, h, i, k, t, l, r, x;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    k = 0;
    tt[k++] = build(0, n);
    while (q--) {
        scanf("%d%d", &t, &h), h--;
        if (t == 1) {
            scanf("%d%d", &i, &x), i--;
            tt[h] = update(tt[h], 0, n, i, x);
        } else if (t == 3) {
            tt[k++] = tt[h];
        } else {
            scanf("%d%d", &l, &r), l--;
            printf("%lld\n", query(tt[h], 0, n, l, r));
        }
    }
    return 0;
}
