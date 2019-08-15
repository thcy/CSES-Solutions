/*
 https://cses.fi/problemset/task/1619
 Movie Festival
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000

int aa[N], bb[N];

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return bb[i] - bb[j];
}

int main() {
    static int ii[N];
    int n, i, j, tmp, t, k;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &aa[i], &bb[i]);
        ii[i] = i;
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    t = 0, k = 0;
    for (i = 0; i < n; i++)
        if (t <= aa[ii[i]])
            t = bb[ii[i]], k++;
    printf("%d\n", k);
    return 0;
}
