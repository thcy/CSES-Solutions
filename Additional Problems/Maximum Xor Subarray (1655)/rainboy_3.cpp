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

void update(int x) {
    int b, i = 1;
    
    for (b = B; b != 0; b >>= 1) {
        int j = (x & b) != 0;
        
        if (!tt[i][j])
            tt[i][j] = ++m;
        i = tt[i][j];
    }
}

int query(int x) {
    int b, i = 1;
    
    for (b = B; b != 0; b >>= 1) {
        int j = (x & b) != 0;
        
        if (tt[i][j ^ 1]) {
            j ^= 1;
            x |= b;
        } else
            x &= ~b;
        i = tt[i][j];
    }
    return x;
}

int main() {
    int n, x, a, ans, y;
    
    scanf("%d", &n);
    x = 0, ans = 0;
    m = 1;
    while (n--) {
        update(x);
        scanf("%d", &a), x ^= a;
        if (ans < (y = query(x)))
            ans = y;
    }
    printf("%d\n", ans);
    return 0;
}
