/*
 https://cses.fi/problemset/task/1661
 Subarray Sums II
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

long long aa[N + 1];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] == aa[j] ? i - j : aa[i] < aa[j] ? -1 : 1;
}

int main() {
    static int ii[N + 1];
    int n, x, h, i, j, tmp;
    long long cnt;
    
    scanf("%d%d", &n, &x);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &aa[i]);
        aa[i] += aa[i - 1];
        ii[i] = i;
    }
    init_rand();
    for (j = 0; j < n; j++) {
        ii[j] = j;
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n + 1, sizeof *ii, compare);
    cnt = 0;
    for (h = 0, i = 0, j = 0; h <= n; h++) {
        long long a = aa[ii[h]] + x;
        
        while (i <= n && (aa[ii[i]] < a || (aa[ii[i]] == a && ii[i] <= ii[h])))
            i++;
        while (j <= n && aa[ii[j]] <= a)
            j++;
        cnt += j - i;
    }
    printf("%lld\n", cnt);
    return 0;
}
