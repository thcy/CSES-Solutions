/*
 https://cses.fi/problemset/task/1068
 Weird Algorithm
 */
#include <stdio.h>

int main() {
    long long n;
    
    scanf("%lld", &n);
    while (n != 1) {
        printf("%lld ", n);
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
    }
    printf("1\n");
    return 0;
}
