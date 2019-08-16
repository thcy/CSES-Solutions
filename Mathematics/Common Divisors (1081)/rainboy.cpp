/*
 https://cses.fi/problemset/task/1081
 Common Divisors
 practice with Dukkha
 */
#include <stdio.h>

#define X    1000000

int main() {
    static int kk[X + 1];
    int n, x, a, b, k;
    
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &x);
        printf("%d\n", x);
        return 0;
    }
    while (n--) {
        scanf("%d", &x);
        kk[x]++;
    }
    for (a = X; a >= 2; a--) {
        k = 0;
        for (b = a; b <= X; b += a)
            k += kk[b];
        if (k >= 2) {
            printf("%d\n", a);
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
