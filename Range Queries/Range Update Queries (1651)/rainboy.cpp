/*
 https://cses.fi/problemset/task/1651
 Range Update Queries
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

long long tt[N];

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] += x;
        i |= i + 1;
    }
}

long long query(int i) {
    long long sum = 0;
    
    while (i >= 0) {
        sum += tt[i];
        i &= i + 1;
        i--;
    }
    return sum;
}

int main() {
    int n, q, i, j, x;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        update(i, n, x);
        update(i + 1, n, -x);
    }
    while (q--) {
        int t;
        
        scanf("%d%d", &t, &i), i--;
        if (t == 1) {
            scanf("%d%d", &j, &x);
            update(i, n, x);
            update(j, n, -x);
        } else
            printf("%lld\n", query(i));
    }
    return 0;
}
