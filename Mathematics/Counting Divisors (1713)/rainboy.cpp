/*
 https://cses.fi/problemset/task/1713
 Counting Divisors
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000000

int main() {
    static int dd[N + 1];
    int a, b, t;
    
    for (a = 1; a <= N; a++)
        for (b = a; b <= N; b += a)
            dd[b]++;
    scanf("%d", &t);
    while (t--) {
        int n;
        
        scanf("%d", &n);
        printf("%d\n", dd[n]);
    }
    return 0;
}
