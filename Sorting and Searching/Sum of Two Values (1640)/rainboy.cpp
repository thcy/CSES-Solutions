/*
 https://cses.fi/problemset/task/1640
 Sum of Two Values
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

int aa[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] - aa[j];
}

int main() {
    static int ii[N];
    int n, x, i, j, tmp, sum;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    init_rand();
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
    }
    qsort(ii, n, sizeof *ii, compare);
    for (i = 0, j = n - 1; i < j; )
        if ((sum = aa[ii[i]] + aa[ii[j]]) == x) {
            printf("%d %d\n", ii[i] + 1, ii[j] + 1);
            return 0;
        } else if (sum < x)
            i++;
        else
            j--;
    printf("IMPOSSIBLE\n");
    return 0;
}
