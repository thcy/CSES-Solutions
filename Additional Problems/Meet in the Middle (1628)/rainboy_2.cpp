/*
 https://cses.fi/problemset/task/1628
 Meet in the Middle
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    40
#define N_    (1 << (N / 2))

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int compare(const void *a, const void *b) {
    long long la = *(long long *) a;
    long long lb = *(long long *) b;
    
    return la == lb ? 0 : la < lb ? -1 : 1;
}

int main() {
    static int aa[N];
    static long long a0[N_], a1[N_];
    int n, n0, n1, k0, k1, x, i, j, b, b_, p, q;
    long long tmp, y, ans;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    k0 = n / 2, k1 = n - k0;
    n0 = 1 << k0, n1 = 1 << k1;
    for (i = 0; i < k0; i++)
        a0[1 << i] = aa[i];
    for (b = 1; b < n0; b++) {
        b_ = b & b - 1;
        a0[b] = a0[b_] + a0[b ^ b_];
    }
    for (i = 0; i < k1; i++)
        a1[1 << i] = aa[k0 + i];
    for (b = 1; b < n1; b++) {
        b_ = b & b - 1;
        a1[b] = a1[b_] + a1[b ^ b_];
    }
    init_rand();
    for (j = 0; j < n0; j++) {
        i = rand_(j + 1);
        tmp = a0[i], a0[i] = a0[j], a0[j] = tmp;
    }
    qsort(a0, n0, sizeof *a0, compare);
    for (j = 0; j < n1; j++) {
        i = rand_(j + 1);
        tmp = a1[i], a1[i] = a1[j], a1[j] = tmp;
    }
    qsort(a1, n1, sizeof *a1, compare);
    ans = 0;
    for (i = 0, p = n1 - 1, q = p; i < n0; i++) {
        while (q >= 0 && (y = a0[i] + a1[q]) > x)
            q--;
        if (q < 0)
            break;
        if (y == x) {
            if (p > q)
                p = q;
            while (p > 0 && a1[p - 1] == a1[q])
                p--;
            ans += q - p + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
