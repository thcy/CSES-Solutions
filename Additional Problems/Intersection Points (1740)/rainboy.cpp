/*
 https://cses.fi/problemset/task/1740
 Intersection Points
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    100000
#define M    1000000
#define INF    (M * 2 + 1)

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct V {
    int y, l, r;
} vv[N * 2];

int compare(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->y != v->y ? u->y - v->y : u->l - v->l;
}

int tt[INF];

void update(int i, int x) {
    while (i < INF) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    
    while (i >= 0) {
        x += tt[i];
        i &= i + 1;
        i--;
    }
    return x;
}

int main() {
    int n, n_, i, j;
    long long ans;
    struct V tmp;
    
    init_rand();
    scanf("%d", &n);
    n_ = 0;
    while (n--) {
        int x1, y1, x2, y2;
        struct V *v;
        
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2), x1 += M, x2 += M;
        if (y1 == y2) {
            v = &vv[n_++];
            v->y = y1, v->l = x1, v->r = x2;
        } else {
            v = &vv[n_++];
            v->y = y1, v->l = -1, v->r = x1;
            v = &vv[n_++];
            v->y = y2, v->l = INF, v->r = x1;
        }
    }
    for (j = 0; j < n_; j++) {
        i = rand_(j + 1);
        tmp = vv[i], vv[i] = vv[j], vv[j] = tmp;
    }
    qsort(vv, n_, sizeof *vv, compare);
    ans = 0;
    for (i = 0; i < n_; i++) {
        struct V *v = &vv[i];
        
        if (v->l == -1)
            update(v->r, 1);
        else if (v->l == INF)
            update(v->r, -1);
        else
            ans += query(v->r) - query(v->l - 1);
    }
    printf("%lld\n", ans);
    return 0;
}
