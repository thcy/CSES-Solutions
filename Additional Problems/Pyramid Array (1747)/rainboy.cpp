/*
 https://cses.fi/problemset/task/1747
 Pyramid Array
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000

int min(int a, int b) { return a < b ? a : b; }

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int aa[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

int tt[N];

void update(int i, int n) {
    while (i < n) {
        tt[i]++;
        i |= i + 1;
    }
}

int query(int i) {
    int sum = 0;
    
    while (i >= 0) {
        sum += tt[i];
        i &= i + 1;
        i--;
    }
    return sum;
}

int main() {
    static int ii[N];
    int n, h, i, j, l, tmp;
    long long ans;
    
    init_rand();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    ans = 0;
    for (h = 0; h < n; h++) {
        i = ii[h];
        l = query(i);
        ans += min(i - l, (n - 1 - i) - (h - l));
        update(i, n);
    }
    printf("%lld\n", ans);
    return 0;
}
