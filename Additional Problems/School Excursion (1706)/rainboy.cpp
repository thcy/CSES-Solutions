/*
 https://cses.fi/problemset/task/1706
 School Excursion
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000

int min(int a, int b) { return a < b ? a : b; }

int dsu[N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return;
    if (dsu[i] > dsu[j]) {
        dsu[j] += dsu[i];
        dsu[i] = j;
    } else {
        dsu[i] += dsu[j];
        dsu[j] = i;
    }
}

int main() {
    static int kk[N + 1], dp[N + 1];
    static char cc[N + 1];
    int n, m, i, j, k, c, a, inf;
    
    scanf("%d%d", &n, &m);
    memset(dsu, -1, sizeof dsu);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        join(i, j);
    }
    for (i = 0; i < n; i++)
        if (dsu[i] < 0) {
            c = -dsu[i];
            kk[c]++;
        }
    inf = n + 1;
    for (i = 1; i <= n; i++)
        dp[i] = inf;
    dp[0] = 0;
    for (c = 1; c <= n; c++) {
        k = kk[c];
        if (k == 0)
            continue;
        for (a = 0; a <= n; a++) {
            if (dp[a] < k)
                dp[a + c] = min(dp[a + c], dp[a] + 1);
            dp[a] = dp[a] <= k ? 0 : inf;
        }
    }
    for (a = 1; a <= n; a++)
        cc[a - 1] = '0' + (dp[a] == 0);
    printf("%s\n", cc);
    return 0;
}
