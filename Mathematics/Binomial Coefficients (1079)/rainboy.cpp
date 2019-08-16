/*
 https://cses.fi/problemset/task/1079
 Binomial Coefficients
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000000
#define MD    1000000007

int ff[N + 1], gg[N + 1];

long long power(int a, int b) {
    long long p;
    
    if (b == 0)
        return 1;
    p = power(a, b / 2);
    p = p * p % MD;
    if (b % 2)
        p = p * a % MD;
    return p;
}

void init() {
    int a;
    long long f = 1;
    
    for (a = 0; a <= N; a++) {
        ff[a] = f;
        gg[a] = power(f, MD - 2);
        f = f * (a + 1) % MD;
    }
}

int main() {
    int n;
    
    init();
    scanf("%d", &n);
    while (n--) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        printf("%lld\n", (long long) ff[a] * gg[b] % MD * gg[a - b] % MD);
    }
    return 0;
}
