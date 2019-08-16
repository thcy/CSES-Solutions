/*
 https://cses.fi/problemset/task/1648
 Range Sum Queries II
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

long long tt[N];

void update(int i, int n, int a) {
    while (i < n) {
        tt[i] += a;
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
    static int aa[N];
    int n, q, i, j, a;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        update(i, n, aa[i]);
    }
    while (q--) {
        int t;
        
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &i, &a), i--;
            update(i, n, a - aa[i]);
            aa[i] = a;
        } else {
            scanf("%d%d", &i, &j), i--, j--;
            printf("%lld\n", query(j) - query(i - 1));
        }
    }
    return 0;
}
