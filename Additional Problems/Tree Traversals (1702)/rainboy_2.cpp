/*
 https://cses.fi/problemset/task/1702
 Tree Traversals
 upsolve with Dukkha
 https://cses.fi/problemset/hack/1702/entry/169043/ (Noam527)
 */
#include <stdio.h>

#define N    100000

int pp[N], ii[N];

void solve(int l, int r) {
    static int cnt;
    int a, i;
    
    if (l == r)
        return;
    a = pp[cnt++], i = ii[a];
    solve(l, i);
    solve(i + 1, r);
    printf("%d ", a + 1);
}

int main() {
    int n, i, a;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &pp[i]), pp[i]--;
    for (i = 0; i < n; i++) {
        scanf("%d", &a), a--;
        ii[a] = i;
    }
    solve(0, n);
    printf("\n");
    return 0;
}
