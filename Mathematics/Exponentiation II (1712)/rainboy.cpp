/*
 https://cses.fi/problemset/task/1712
 Exponentiation II
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007
#define T    (MD - 1)

long long power(int a, int k, int md) {
    long long p;
    
    if (k == 0)
        return 1;
    p = power(a, k / 2, md);
    p = p * p % md;
    if (k % 2)
        p = p * a % md;
    return p;
}

int main() {
    int n;
    
    scanf("%d", &n);
    while (n--) {
        int a, b, c;
        
        scanf("%d%d%d", &a, &b, &c);
        printf("%lld\n", power(a, power(b, c, T), MD));
    }
    return 0;
}
