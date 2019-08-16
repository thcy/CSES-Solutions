/*
 https://cses.fi/problemset/task/1717
 Christmas Party
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

int main() {
    int n, a, b, k, i;
    
    scanf("%d", &n);
    if (n == 1)
        k = 0;
    else {
        a = 0, b = 1;
        k = b;
        for (i = 2; i < n; i++)
            k = (long long) (a + b) * i % MD, a = b, b = k;
    }
    printf("%d\n", k);
    return 0;
}
