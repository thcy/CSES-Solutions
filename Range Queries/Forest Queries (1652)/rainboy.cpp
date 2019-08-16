/*
 https://cses.fi/problemset/task/1652
 Forest Queries
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000

int main() {
    static int aa[N + 1][N + 1];
    int n, q, i, j;
    
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) {
        static char s[N + 2];
        
        scanf("%s", s + 1);
        for (j = 1; j <= n; j++)
            aa[i][j] = s[j] == '*';
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            aa[i][j] += aa[i - 1][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            aa[i][j] += aa[i][j - 1];
    while (q--) {
        int i1, j1, i2, j2;
        
        scanf("%d%d%d%d", &i1, &j1, &i2, &j2), i1--, j1--;
        printf("%d\n", aa[i2][j2] - aa[i1][j2] - aa[i2][j1] + aa[i1][j1]);
    }
    return 0;
}
