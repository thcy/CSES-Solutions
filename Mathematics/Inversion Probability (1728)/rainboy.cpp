/*
 https://cses.fi/problemset/task/1728
 Inversion Probability
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100
#define A    100

void update(int *tt, int i, int x) {
    while (i <= A) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int *tt, int i) {
    int sum = 0;
    
    while (i >= 0) {
        sum += tt[i];
        i &= i + 1;
        i--;
    }
    return sum;
}

int main() {
    static int aa[N], t1[A + 1], t2[A + 1];
    int n, i, a, b, sum, cnt;
    double ans;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    ans = 0;
    for (i = 0; i < n; i++) {
        b = aa[i];
        sum = query(t2, b);
        ans += sum / 2.0 / b;
        update(t2, b, b - 1);
    }
    memset(t2, 0, sizeof t2);
    for (i = n - 1; i >= 0; i--) {
        a = aa[i];
        sum = query(t2, a - 1);
        cnt = query(t1, a - 1);
        ans += cnt - sum / 2.0 / a;
        update(t2, a, a + 1);
        update(t1, a, 1);
    }
    printf("%.6f\n", ans);
    return 0;
}
