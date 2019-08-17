/*
 https://cses.fi/problemset/task/1655
 Maximum Xor Subarray
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define M    (1 + N * K)
#define K    30
#define B    (1 << (K - 1))

int tt[1 + M][2], m;

int update(int i, int x, int b) {
    if (i == 0)
        i = ++m;
    if (b > 0) {
        int j = (x & b) != 0;
        
        tt[i][j] = update(tt[i][j], x, b >> 1);
    }
    return i;
}

int query(int i, int x, int b) {
    while (b > 0) {
        int j = (x & b) == 0;
        
        if (tt[i][j])
            x |= b;
        else {
            j ^= 1;
            x &= ~b;
        }
        i = tt[i][j];
        b >>= 1;
    }
    return x;
}

int main() {
    int n, x, a, i, ans, y;
    
    scanf("%d", &n);
    x = 0, i = 0, ans = 0;
    while (n--) {
        i = update(i, x, B);
        scanf("%d", &a), x ^= a;
        if (ans < (y = query(i, x, B)))
            ans = y;
    }
    printf("%d\n", ans);
    return 0;
}
