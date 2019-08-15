/*
 https://cses.fi/problemset/task/1618
 Trailing Zeros
 practice with Dukkha
 */
#include <stdio.h>

int zeros(int n) {
    return n == 0 ? 0 : zeros(n / 5) + n / 5;
}

int main() {
    int n;
    
    scanf("%d", &n);
    printf("%d\n", zeros(n));
    return 0;
}
