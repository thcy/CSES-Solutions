/*
 https://cses.fi/problemset/task/1697
 Chess Tournament
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

struct V {
    struct V *next;
    int i;
} vv[N];

struct L {
    struct L *next;
    struct V *head, *tail;
    int d, k;
} ll[N + 1];

void push(struct L *l, struct V *v) {
    if (l->k == 0)
        l->head = l->tail = v;
    else
        v->next = l->head, l->head = v;
    l->k++;
}

struct V *pop(struct L *l) {
    struct V *v = l->head;
    
    l->head = l->head->next;
    if (l->head == NULL)
        l->tail = NULL;
    l->k--;
    return v;
}

struct L *cut(struct L *a, int k) {
    static struct L l91[N], *b = l91;
    struct L *c;
    
    b->d = a->d;
    b->k = k; a->k -= k;
    b->tail = b->head = a->head;
    while (--k)
        b->tail = b->tail->next;
    a->head = b->tail->next; b->tail->next = NULL;
    if (a->head == NULL)
        a->tail = NULL;
    c = a->next; a->next = b; b->next = c;
    return b++;
}

void join(struct L *a) {
    struct L *b = a->next;
    
    while (b && a->d == b->d) {
        if (b->k) {
            a->k += b->k;
            a->tail->next = b->head;
            a->tail = b->tail;
        }
        b = b->next;
    }
    a->next = b;
}

int ee[M], m;

void add(int i, struct L *l) {
    struct V *v;
    
    for (v = l->head; v; v = v->next)
        ee[m++] = i, ee[m++] = v->i;
}

int main() {
    int n, i, d;
    struct L *l, *l_;
    
    scanf("%d", &n);
    for (d = 0; d <= n; d++)
        ll[d].d = d;
    for (i = 0; i < n; i++) {
        int d;
        
        scanf("%d", &d);
        if (d >= n) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        vv[i].i = i + 1;
        push(&ll[d], &vv[i]);
    }
    l = NULL;
    for (d = 0; d < n; d++)
        if (ll[d].k)
            ll[d].next = l, l = &ll[d];
    l_ = l;
    while ((l = l_)) {
        if (l->k == 0) {
            l_ = l->next;
            continue;
        }
        i = pop(l)->i, d = l->d;
        while (d > 0) {
            if (l == NULL || l->d == 0) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
            if (l->k) {
                join(l);
                if (l->k > d)
                    l = cut(l, d);
                add(i, l); l->d--; d -= l->k;
            }
            l = l->next;
        }
    }
    printf("%d\n", m / 2);
    while (m) {
        printf("%d %d\n", ee[m - 1], ee[m - 2]);
        m -= 2;
    }
    return 0;
}
