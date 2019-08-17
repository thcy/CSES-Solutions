/*
 https://cses.fi/problemset/task/1677
 Network Breakdown
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N    100000
#define M    200000
#define K    200000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int aa[M + K], bb[M + K];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] != aa[j] ? aa[i] - aa[j] : bb[i] - bb[j];
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
    static int ii[M + K], ans[K];
    static char dup[M + K];
    int n, m, k, h, i, j, tmp, c;
    
    init_rand();
    scanf("%d%d%d", &n, &m, &k);
    for (h = 0; h < m + k; h++) {
        scanf("%d%d", &aa[h], &bb[h]), aa[h]--, bb[h]--;
        if (aa[h] > bb[h])
            tmp = aa[h], aa[h] = bb[h], bb[h] = tmp;
    }
    for (h = 0; h < m + k; h++)
        ii[h] = h;
    for (j = 0; j < m + k; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, m + k, sizeof *ii, compare);
    for (h = 1; h < m + k; h++) {
        i = ii[h - 1];
        j = ii[h];
        if (aa[i] == aa[j] && bb[i] == bb[j])
            dup[i] = dup[j] = 1;
    }
    memset(dsu, -1, n * sizeof *dsu);
    c = n;
    for (h = 0; h < m; h++)
        if (!dup[h] && join(aa[h], bb[h]))
            c--;
    for (h = k - 1; h >= 0; h--) {
        ans[h] = c;
        if (join(aa[m + h], bb[m + h]))
            c--;
    }
    for (h = 0; h < k; h++)
        printf("%d ", ans[h]);
    printf("\n");
    return 0;
}
