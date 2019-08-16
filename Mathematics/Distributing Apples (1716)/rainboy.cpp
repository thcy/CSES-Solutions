/*
 https://cses.fi/problemset/task/1716
 Distributing Apples
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

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

int choose(int a, int b) {
    int c = a - b, fa, fb, fc, f, i;
    
    f = 1;
    for (i = 0; i <= a; i++) {
        if (i == a)
            fa = f;
        if (i == b)
            fb = f;
        if (i == c)
            fc = f;
        f = (long long) f * (i + 1) % MD;
    }
    return fa * power((long long) fb * fc % MD, MD - 2) % MD;
}

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    printf("%d\n", choose(m + n - 1, m));
    return 0;
}
