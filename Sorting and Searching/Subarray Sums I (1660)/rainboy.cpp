/*
 https://cses.fi/problemset/task/1660
 Subarray Sums I
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int aa[N];
    int n, x, i, j, a, cnt;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    a = 0;
    cnt = 0;
    for (i = 0, j = 0; j < n; j++) {
        a += aa[j];
        while (a > x)
            a -= aa[i++];
        if (a == x)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
