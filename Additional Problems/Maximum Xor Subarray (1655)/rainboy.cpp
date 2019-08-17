/*
 https://cses.fi/problemset/task/1655
 Maximum Xor Subarray
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000
#define K    30

struct T {
    struct T *tt[2];
};

struct T *new_T() {
    static struct T t91[1 + (N + 1) * K], *t = t91;
    
    return t++;
}

struct T *update(struct T *t, int x, int b) {
    if (t == NULL)
        t = new_T();
    if (b > 0) {
        int i = (x & b) != 0;
        
        t->tt[i] = update(t->tt[i], x, b >> 1);
    }
    return t;
}

int query(struct T *t, int x, int b) {
    while (b > 0) {
        int i = (x & b) == 0;
        
        if (t->tt[i])
            x |= b;
        else {
            i ^= 1;
            x &= ~b;
        }
        t = t->tt[i];
        b >>= 1;
    }
    return x;
}

int main() {
    struct T *t;
    int n, x, a, ans, y;
    
    scanf("%d", &n);
    x = 0;
    t = update(NULL, x, 1 << (K - 1));
    ans = 0;
    while (n--) {
        scanf("%d", &a), x ^= a;
        if (ans < (y = query(t, x, 1 << (K - 1))))
            ans = y;
        t = update(t, x, 1 << (K - 1));
    }
    printf("%d\n", ans);
    return 0;
}
