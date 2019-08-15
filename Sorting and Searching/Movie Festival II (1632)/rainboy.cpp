/*
 https://cses.fi/problemset/task/1632
 Movie Festival II
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000
#define MD    1000000007

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct V {
    struct V *l, *r;
    int key, cnt, x;
} *v_, *l_, *r_;

struct V *new_V(int key) {
    struct V *v = (struct V *) calloc(1, sizeof *v);
    
    v->key = key;
    v->x = rand_(MD);
    return v;
}

void split(struct V *v, int key) {
    if (v == NULL)
        v_ = l_ = r_ = NULL;
    else if (v->key < key) {
        split(v->r, key);
        v->r = l_; l_ = v;
    } else if (v->key > key) {
        split(v->l, key);
        v->l = r_; r_ = v;
    } else {
        v_ = v;
        l_ = v->l;
        r_ = v->r;
        v->l = v->r = NULL;
    }
}

struct V *merge(struct V *l, struct V *r) {
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    if (l->x <= r->x) {
        l->r = merge(l->r, r);
        return l;
    } else {
        r->l = merge(l, r->l);
        return r;
    }
}

struct V *last(struct V *v) {
    if (v)
        while (v->r)
            v = v->r;
    return v;
}

void tr_add(int key) {
    split(v_, key);
    if (v_ == NULL)
        v_ = new_V(key);
    v_->cnt++;
    v_ = merge(l_, merge(v_, r_));
}

void tr_remove(int key) {
    split(v_, key);
    if (--v_->cnt == 0)
        free(v_), v_ = NULL;
    v_ = merge(l_, merge(v_, r_));
}

struct V *tr_floor(int key) {
    struct V *v;
    
    split(v_, key);
    v = v_ ? v_ : last(l_);
    v_ = merge(l_, merge(v_, r_));
    return v;
}

int aa[N], bb[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return bb[i] - bb[j];
}

int main() {
    static int ii[N];
    int n, k, i, j, tmp, cnt;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &aa[i], &bb[i]);
        ii[i] = i;
    }
    init_rand();
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    while (k--)
        tr_add(0);
    cnt = 0;
    for (i = 0; i < n; i++) {
        struct V *v = tr_floor(aa[ii[i]]);
        
        if (v) {
            tr_remove(v->key);
            tr_add(bb[ii[i]]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
