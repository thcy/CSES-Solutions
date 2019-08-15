/*
 https://cses.fi/problemset/task/1145
 Increasing Subsequence
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

int aa[N], tt[N];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return aa[i] != aa[j] ? aa[i] - aa[j] : j - i;
}

void update(int i, int n, int x) {
    while (i < n) {
        if (tt[i] < x)
            tt[i] = x;
        i |= i + 1;
    }
}

int query(int i) {
    int ans = 0;
    
    while (i >= 0) {
        if (ans < tt[i])
            ans = tt[i];
        i &= i + 1;
        i--;
    }
    return ans;
}

int main() {
    static int ii[N];
    int n, i, ans, cnt;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    qsort(ii, n, sizeof *ii, compare);
    ans = 0;
    for (i = 0; i < n; i++) {
        if (ans < (cnt = query(ii[i]) + 1))
            ans = cnt;
        update(ii[i], n, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
