/*
 https://cses.fi/problemset/task/1675
 Road Reparation
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N    100000
#define M    200000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct E {
    int i, j, w;
} ee[M];

int compare(const void *a, const void *b) {
    struct E *e = (struct E *) a;
    struct E *f = (struct E *) b;
    
    return e->w - f->w;
}

int dsu[N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

int join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return 0;
    if (dsu[i] > dsu[j])
        dsu[i] = j;
    else {
        if (dsu[i] == dsu[j])
            dsu[i]--;
        dsu[j] = i;
    }
    return 1;
}

int main() {
    int n, m, h, h_;
    long long ans;
    struct E *e, tmp;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        e = &ee[h];
        scanf("%d%d%d", &e->i, &e->j, &e->w), e->i--, e->j--;
    }
    init_rand();
    for (h = 0; h < m; h++) {
        h_ = rand_(h + 1);
        tmp = ee[h], ee[h] = ee[h_], ee[h_] = tmp;
    }
    qsort(ee, m, sizeof *ee, compare);
    memset(dsu, -1, n * sizeof *dsu);
    ans = 0;
    for (h = 0; h < m && n > 1; h++) {
        e = &ee[h];
        if (join(e->i, e->j)) {
            ans += e->w;
            n--;
        }
    }
    if (n > 1)
        printf("IMPOSSIBLE\n");
    else
        printf("%lld\n", ans);
    return 0;
}
