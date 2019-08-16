/*
 https://cses.fi/problemset/task/1734
 Distinct Values Queries
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    200000
#define Q    200000

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int aa[N];

int compare_a(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] != aa[j] ? aa[i] - aa[j] : i - j;
}

int ll[Q], rr[Q];

int compare_r(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return rr[i] - rr[j];
}

int tt[N];

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] += x;
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
    static int ii[N], pp[N], dd[Q];
    int n, q, h, h_, i, j, r, r_, tmp;
    
    init_rand();
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare_a);
    for (i = 0; i < n; i++)
        pp[ii[i]] = i == 0 || aa[ii[i - 1]] != aa[ii[i]] ? n : ii[i - 1];
    for (h = 0; h < q; h++) {
        scanf("%d%d", &ll[h], &rr[h]), ll[h]--, rr[h]--;
        ii[h] = h;
    }
    for (j = 0; j < q; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, q, sizeof *ii, compare_r);
    for (h = 0, r = 0; h < q; ) {
        r_ = rr[ii[h]];
        while (r <= r_) {
            update(pp[r], n, -1);
            update(r, n, 1);
            r++;
        }
        while (h < q && rr[h_ = ii[h]] == r_) {
            dd[h_] = query(rr[h_]) - query(ll[h_] - 1);
            h++;
        }
    }
    for (h = 0; h < q; h++)
        printf("%d\n", dd[h]);
    return 0;
}
