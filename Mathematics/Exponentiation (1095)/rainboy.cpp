/*
 https://cses.fi/problemset/task/1095
 Exponentiation
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

long long power(int a, int b) {
    long long p;
    
    if (b == 0)
        return 1;
    p = power(a, b / 2);
    p = p * p % MD;
    if (b % 2 == 1)
        p = p * a % MD;
    return p;
}

int main() {
    int n;
    
    scanf("%d", &n);
    while (n--) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        printf("%lld\n", power(a, b));
    }
    return 0;
}
