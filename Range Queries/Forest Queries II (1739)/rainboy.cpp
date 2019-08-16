/*
 https://cses.fi/problemset/task/1739
 Forest Queries II
 practice with Dukkha
 */
#include <stdio.h>

#define N    1000

int tt[N][N];

void update(int i, int j_, int n, int x) {
    while (i < n) {
        int j = j_;
        
        while (j < n) {
            tt[i][j] += x;
            j |= j + 1;
        }
        i |= i + 1;
    }
}

int query(int i, int j_) {
    int sum = 0;
    
    while (i >= 0) {
        int j = j_;
        
        while (j >= 0) {
            sum += tt[i][j];
            j &= j + 1;
            j--;
        }
        i &= i + 1;
        i--;
    }
    return sum;
}

int main() {
    static char cc[N][N];
    static int aa[N + 1][N + 1];
    int n, q, i, j, i1, j1, i2, j2, a;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            aa[i + 1][j + 1] = cc[i][j] = cc[i][j] == '*';
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            aa[i][j] += aa[i][j - 1];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            aa[i][j] += aa[i - 1][j];
    while (q--) {
        int t;
        
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &i, &j), i--, j--;
            update(i, j, n, (cc[i][j] ^= 1) ? 1 : -1);
        } else {
            scanf("%d%d%d%d", &i1, &j1, &i2, &j2), i1--, j1--;
            a = aa[i2][j2] - aa[i1][j2] - aa[i2][j1] + aa[i1][j1];
            i1--, j1--, i2--, j2--;
            a += query(i2, j2) - query(i1, j2) - query(i2, j1) + query(i1, j1);
            printf("%d\n", a);
        }
    }
    return 0;
}
