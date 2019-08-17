/*
 https://cses.fi/problemset/task/1078
 Grid Paths
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    1000000
#define M    1000
#define MD    1000000007

int xx[M + 1], yy[M + 1], zz[M + 1], ii[M + 1];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return xx[i] != xx[j] ? xx[i] - xx[j] : yy[i] - yy[j];
}

int ff[N * 2], gg[N * 2];

long long power(int a, int k) {
    long long p;
    
    if (k == 0)
        return 1;
    p = power(a, k / 2);
    p = p * p % MD;
    if (k % 2)
        p = p * a % MD;
    return p;
}

void init(int n) {
    int i;
    long long f = 1;
    
    for (i = 0; i < n; i++) {
        ff[i] = f;
        gg[i] = power(f, MD - 2);
        f = f * (i + 1) % MD;
    }
}

long long choose(int n, int k) {
    return (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}

int main() {
    int n, m, h, h_, i, j, x, y, z;
    
    scanf("%d%d", &n, &m);
    init(n * 2);
    for (h = 0; h < m; h++)
        scanf("%d%d", &xx[h], &yy[h]), xx[h]--, yy[h]--;
    xx[m] = yy[m] = n - 1;
    for (h = 0; h <= m; h++)
        ii[h] = h;
    qsort(ii, m + 1, sizeof *ii, compare);
    for (h = 0; h <= m; h++) {
        j = ii[h];
        x = xx[j];
        y = yy[j];
        z = choose(x + y, x);
        for (h_ = 0; h_ < h; h_++) {
            i = ii[h_];
            if (xx[i] <= xx[j] && yy[i] <= yy[j]) {
                x = xx[j] - xx[i];
                y = yy[j] - yy[i];
                z = (z - zz[i] * choose(x + y, x)) % MD;
            }
        }
        zz[j] = z;
    }
    printf("%d\n", (zz[m] + MD) % MD);
    return 0;
}
