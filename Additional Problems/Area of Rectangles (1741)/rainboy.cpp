/*
 https://cses.fi/problemset/task/1741
 Area of Rectangles
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    100000
#define Z    1000000
#define A    (1 << 21)

struct V {
    int y, l, r, add;
} vv[N * 2];

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int compare(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->y - v->y;
}

int tr[A * 2], zz[A * 2];

void update(int k, int l, int r, int ql, int qr, int x) {
    int k1, k2;
    
    if (qr <= l || r <= ql)
        return;
    k1 = k * 2 + 1;
    k2 = k * 2 + 2;
    if (ql <= l && r <= qr)
        zz[k] += x;
    else {
        int m = (l + r) / 2;
        
        update(k1, l, m, ql, qr, x);
        update(k2, m, r, ql, qr, x);
    }
    tr[k] = zz[k] ? r - l : r - l == 1 ? 0 : tr[k1] + tr[k2];
}

int main() {
    int n, m, h, i, j, x1, y1, x2, y2, y;
    long long ans;
    struct V tmp;
    
    init_rand();
    scanf("%d", &n);
    m = 0;
    for (i = 0; i < n; i++) {
        struct V *v;
        
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2), x1 += Z, y1 += Z, x2 += Z, y2 += Z;
        v = &vv[m++];
        v->y = y1, v->l = x1, v->r = x2, v->add = 1;
        v = &vv[m++];
        v->y = y2, v->l = x1, v->r = x2, v->add = 0;
    }
    for (j = 0; j < m; j++) {
        i = rand_(j + 1);
        tmp = vv[i], vv[i] = vv[j], vv[j] = tmp;
    }
    qsort(vv, m, sizeof *vv, compare);
    y = -1;
    ans = 0;
    for (h = 0; h < m; h++) {
        struct V *v = &vv[h];
        
        if (y != -1)
            ans += (long long) (v->y - y) * tr[0];
        y = v->y;
        update(0, 0, A, v->l, v->r, v->add ? 1 : -1);
    }
    printf("%lld\n", ans);
    return 0;
}
