/*
 https://cses.fi/problemset/task/1748
 Increasing Subsequence II
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

int xx[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return xx[i] != xx[j] ? xx[i] - xx[j] : j - i;
}

int tt[N];

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] = (tt[i] + x) % MD;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    
    while (i >= 0) {
        x = (x + tt[i]) % MD;
        i &= i + 1;
        i--;
    }
    return x;
}

int main() {
    static int ii[N];
    int n, h, i, j, tmp;
    
    init_rand();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &xx[i]);
        ii[i] = i;
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    for (h = 0; h < n; h++)
        update(ii[h], n, query(ii[h]) + 1);
    printf("%d\n", query(n - 1));
    return 0;
}
