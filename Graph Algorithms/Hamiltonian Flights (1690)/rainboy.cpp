/*
 https://cses.fi/problemset/task/1690
 Hamiltonian Flights
 practice with Dukkha
 */
#include <stdio.h>

#define N    20
#define MD    1000000007

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[N * N], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int main() {
    static int dp[1 << N][N];
    int n, m, i, j, b, b_, x;
    struct L *l;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    dp[1 << 0][0] = 1;
    for (b = 1; b < 1 << n; b += 2)
        for (i = 0; i < n - 1; i++) {
            x = dp[b][i];
            if (x == 0)
                continue;
            for (l = aa[i].next; l; l = l->next)
                if (!(b & 1 << (j = l->j))) {
                    b_ = b | 1 << j;
                    dp[b_][j] = (dp[b_][j] + x) % MD;
                }
        }
    printf("%d\n", dp[(1 << n) - 1][n - 1]);
    return 0;
}
