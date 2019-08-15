/*
 https://cses.fi/problemset/task/1158
 Book Shop
 */
#include <stdio.h>

#define N    1000
#define X    100000

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    static int hh[N], ss[N], dp[X + 1];
    int n, x, i, y;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &hh[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &ss[i]);
    for (i = 0; i < n; i++) {
        int h = hh[i], s = ss[i];
        
        for (y = x; y >= h; y--)
            dp[y] = max(dp[y], dp[y - h] + s);
    }
    printf("%d\n", dp[x]);
    return 0;
}
