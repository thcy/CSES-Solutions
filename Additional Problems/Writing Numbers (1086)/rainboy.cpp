/*
 practice with Dukkha
 https://cses.fi/problemset/task/1086
 Writing Numbers
 */
#include <stdio.h>

long long p10[19], pp[19], qq[19], dd[19];

void init() {
    int i;
    long long p = 1;
    
    for (i = 0; i < 19; i++) {
        p10[i] = p;
        p *= 10;
    }
}

int preprocess(long long x) {
    long long p = x, q = 0, d;
    int k = 0;
    
    while (x > 0) {
        d = (dd[k] = x % 10) * p10[k];
        p /= 10;
        pp[k] = p;
        qq[k] = q;
        q += d;
        k++;
        x /= 10;
    }
    return k;
}

long long count(int k, int b) {
    int i;
    long long ans;
    
    ans = 0;
    for (i = 0; i < k - 1 + b; i++) {
        ans += (pp[i] - 1 + b) * p10[i];
        if (dd[i] >= b)
            ans += dd[i] == b ? 1 + qq[i] : p10[i];
    }
    return ans;
}

int main() {
    long long n, lower, upper;
    
    init();
    scanf("%lld", &n);
    /* (x - 10^17) * 18 / 10 <= n */
    lower =    0, upper = 1000000000000000000LL;
    while (upper - lower > 1) {
        long long x = (lower + upper) / 2;
        int k = preprocess(x);
        
        if (count(k, 0) <= n && count(k, 1) <= n)
            lower = x;
        else
            upper = x;
    }
    printf("%lld\n", lower);
    return 0;
}
