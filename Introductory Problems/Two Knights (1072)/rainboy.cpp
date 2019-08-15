/*
 https://cses.fi/problemset/task/1072
 Two Knights
 */
#include <stdio.h>

int main() {
    int n, k;
    
    scanf("%d", &n);
    for (k = 1; k <= n; k++)
    printf("%lld\n", (long long) k * k * (k * k - 1) / 2 - (k - 1) * (k - 2) * 4);
    return 0;
}
