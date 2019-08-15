/*
 https://cses.fi/problemset/task/1623
 Apple Division
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    20

long long abs_(long long a) {
    return a > 0 ? a : -a;
}

int main() {
    static int pp[N];
    int n, i, b;
    long long sum, sum_, d_, d;
    
    scanf("%d", &n);
    sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &pp[i]);
        sum += pp[i];
    }
    d_ = sum;
    for (b = 0; b < 1 << (n - 1); b++) {
        sum_ = 0;
        for (i = 0; i < n - 1; i++)
            if (b & 1 << i)
                sum_ += pp[i];
        if (d_ > (d = abs_(sum_ - (sum - sum_))))
            d_ = d;
    }
    printf("%lld\n", d_);
    return 0;
}
