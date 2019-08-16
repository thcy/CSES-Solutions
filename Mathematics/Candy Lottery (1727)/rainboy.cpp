/*
 https://cses.fi/problemset/task/1727
 Candy Lottery
 practice with Dukkha
 */
#include <stdio.h>

double power(double a, int k) {
    double p;
    
    if (k == 0)
        return 1;
    p = power(a, k / 2);
    p *= p;
    if (k % 2)
        p *= a;
    return p;
}

int main() {
    int n, k, x;
    double ans;
    
    scanf("%d%d", &n, &k);
    ans = k;
    for (x = 1; x < k; x++)
        ans -= power((double) x / k, n);
    printf("%.6f\n", ans);
    return 0;
}
