/*
 https://cses.fi/problemset/task/1619
 Restaurant Customers
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static int aa[N * 2];
    int n, i, j, a, b, tmp, max, k;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        aa[i * 2 + 0] = a * 2 + 0;
        aa[i * 2 + 1] = b * 2 + 1;
    }
    init_rand();
    for (j = 0; j < n * 2; j++) {
        i = rand_(j + 1);
        tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
    }
    qsort(aa, n * 2, sizeof *aa, compare);
    max = k = 0;
    for (i = 0; i < n * 2; i++)
        if (max < (k += aa[i] % 2 == 0 ? 1 : -1))
            max = k;
    printf("%d\n", max);
    return 0;
}
