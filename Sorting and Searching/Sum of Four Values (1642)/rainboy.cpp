/*
 https://cses.fi/problemset/task/1642
 Sum of Four Values
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    1000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int aa[N];

struct V {
    int a, l, r;
} vv[N * (N - 1) / 2];

int compare_a(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

int compare_al(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->a != v->a ? u->a - v->a : u->l - v->l;
}

int main() {
    static int ii[N];
    int n, x, i, j, m;
    struct V tmp;
    long long a;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare_a);
    m = 0;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            struct V *v = &vv[m++];
            
            v->a = aa[ii[i]] + aa[ii[j]], v->l = i, v->r = j;
        }
    init_rand();
    for (j = 0; j < m; j++) {
        i = rand_(j + 1);
        tmp = vv[i], vv[i] = vv[j], vv[j] = tmp;
    }
    qsort(vv, m, sizeof *vv, compare_al);
    for (i = 0, j = m - 1; i < j; i++) {
        a = vv[i].a;
        while (i < j && a + vv[j].a > x)
            j--;
        if (i < j && a + vv[j].a == x && vv[i].r < vv[j].l) {
            int il = ii[vv[i].l] + 1, ir = ii[vv[i].r] + 1;
            int jl = ii[vv[j].l] + 1, jr = ii[vv[j].r] + 1;
            
            printf("%d %d %d %d\n", il, ir, jl, jr);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
