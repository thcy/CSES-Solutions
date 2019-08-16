/*
 https://cses.fi/problemset/task/1715
 Creating Strings II
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000
#define A    26
#define MD    1000000007

long long power(int a, int k) {
    long long p;
    
    if (k == 0)
        return 1;
    p = power(a, k / 2);
    p = p * p % MD;
    if (k % 2)
        p = p * a % MD;
    return p;
}

int main() {
    static char cc[N + 1];
    static int kk[A], ff[N + 1];
    int n, i, f, c;
    long long ans;
    
    scanf("%s", cc);
    n = strlen(cc);
    for (i = 0; i < n; i++)
        kk[cc[i] - 'a']++;
    for (i = 0, f = 1; i <= n; i++) {
        ff[i] = f;
        f = (long long) f * (i + 1) % MD;
    }
    ans = ff[n];
    for (c = 0; c < 26; c++)
        ans = ans * power(ff[kk[c]], MD - 2) % MD;
    printf("%lld\n", ans);
    return 0;
}
