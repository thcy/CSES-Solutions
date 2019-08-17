/*
 https://cses.fi/problemset/task/1664
 Movie Festival Queries
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000
#define A    1000000
#define K    17    /* K = floor(log2(N)) */

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct V {
    int a, b;
} vv[N];

int compare(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->b - v->b;
}

int main() {
    static int pp[K + 1][A + 1];
    int n, q, h, i, j, a, a_, b, m;
    struct V tmp;
    
    init_rand();
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) {
        struct V *v = &vv[i];
        
        scanf("%d%d", &v->a, &v->b);
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = vv[i], vv[i] = vv[j], vv[j] = tmp;
    }
    qsort(vv, n, sizeof *vv, compare);
    for (a = 0, b = 0, i = 0; b <= A; b++) {
        while (i < n && vv[i].b == b) {
            if (a < (a_ = vv[i].a))
                a = a_;
            i++;
        }
        pp[0][b] = a;
    }
    for (h = 1; h <= K; h++)
        for (a = 0; a <= A; a++)
            pp[h][a] = pp[h - 1][pp[h - 1][a]];
    while (q--) {
        scanf("%d%d", &a, &b);
        m = 0;
        for (h = K; h >= 0; h--)
            if (pp[h][b] >= a) {
                b = pp[h][b];
                m += 1 << h;
            }
        printf("%d\n", m);
    }
    return 0;
}
