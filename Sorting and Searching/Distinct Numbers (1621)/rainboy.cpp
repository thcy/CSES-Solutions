/*
 https://cses.fi/problemset/task/1621
 Distinct Numbers
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
    static int aa[N];
    int n, i, j, tmp, cnt;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    init_rand();
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
    }
    qsort(aa, n, sizeof *aa, compare);
    cnt = 1;
    for (i = 1; i < n; i++)
        if (aa[i - 1] != aa[i])
            cnt++;
    printf("%d\n", cnt);
    return 0;
}
