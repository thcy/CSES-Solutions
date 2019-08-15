/*
 https://cses.fi/problemset/task/1745
 Money Sums
 practice with Dukkha
 */
#include <stdio.h>

#define N    100
#define X    1000
#define S    (N * X)

int main() {
    static char dp[S + 1];
    int n, x, s, k;
    
    scanf("%d", &n);
    dp[0] = 1;
    while (n--) {
        scanf("%d", &x);
        for (s = S; s >= x; s--)
            dp[s] |= dp[s - x];
    }
    k = 0;
    for (s = 1; s <= S; s++)
        if (dp[s])
            k++;
    printf("%d\n", k);
    for (s = 1; s <= S; s++)
        if (dp[s])
            printf("%d ", s);
    printf("\n");
    return 0;
}
