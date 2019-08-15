/*
 practice with Dukkha
 https://cses.fi/problemset/task/1140
 Projects
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

struct V {
    int a, b;
    long long p;
} vv[N];

int compare(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->b - v->b;
}

int main() {
    int n, i, j, lower, upper;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct V *v = &vv[i];
        
        scanf("%d%d%lld", &v->a, &v->b, &v->p);
    }
    qsort(vv, n, sizeof *vv, compare);
    for (j = 0; j < n; j++) {
        lower = -1, upper = j;
        while (upper - lower > 1) {
            i = (lower + upper) / 2;
            if (vv[i].b < vv[j].a)
                lower = i;
            else
                upper = i;
        }
        if (lower != -1)
            vv[j].p += vv[lower].p;
        if (j > 0 && vv[j].p < vv[j - 1].p)
            vv[j].p = vv[j - 1].p;
    }
    printf("%lld\n", vv[n - 1].p);
    return 0;
}
