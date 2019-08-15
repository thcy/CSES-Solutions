/*
 https://cses.fi/problemset/task/1085
 Array Division
 */
#include <stdio.h>

#define N    200000

int count(int *aa, int n, long long x) {
    long long a;
    int i, k;
    
    a = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        if (a + aa[i] > x) {
            a = 0;
            k++;
        }
        a += aa[i];
    }
    return k + 1;
}

int main() {
    static int aa[N];
    int n, k, i, max;
    long long sum, lower, upper, x;
    
    scanf("%d%d", &n, &k);
    max = 0, sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        sum += aa[i];
        if (max < aa[i])
            max = aa[i];
    }
    lower = max - 1, upper = sum;
    while (upper - lower > 1) {
        x = (lower + upper) / 2;
        if (count(aa, n, x) <= k)
            upper = x;
        else
            lower = x;
    }
    printf("%lld\n", upper);
    return 0;
}
