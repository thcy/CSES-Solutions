/*
 https://cses.fi/problemset/task/1162
 Sorting Methods
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    200000

int tt[N];

void update(int i, int n) {
    while (i < n) {
        tt[i]++;
        i |= i + 1;
    }
}

int query(int i) {
    int cnt = 0;
    
    while (i >= 0) {
        cnt += tt[i];
        i &= i + 1;
        i--;
    }
    return cnt;
}

void update_max(int i, int n, int x) {
    while (i < n) {
        if (tt[i] < x)
            tt[i] = x;
        i |= i + 1;
    }
}

int query_max(int i) {
    int max = 0;
    
    while (i >= 0) {
        if (max < tt[i])
            max = tt[i];
        i &= i + 1;
        i--;
    }
    return max;
}

long long solve1(int *aa, int n) {
    long long sum = 0;
    int i;
    
    memset(tt, 0, sizeof tt);
    for (i = 0; i < n; i++) {
        sum += query(aa[i]);
        update(aa[i], n);
    }
    return (long long) n * (n - 1) / 2 - sum;
}

int solve2(int *aa, int n) {
    static char used[N];
    int i, j, cnt;
    
    memset(used, 0, sizeof used);
    cnt = 0;
    for (i = 0; i < n; i++)
        if (!used[i]) {
            cnt++;
            for (j = i; !used[j]; j = aa[j])
                used[j] = 1;
        }
    return n - cnt;
}

int solve3(int *aa, int n) {
    int i;
    
    memset(tt, 0, sizeof tt);
    for (i = 0; i < n; i++)
        update_max(aa[i], n, query_max(aa[i]) + 1);
    return n - query_max(n - 1);
}

int solve4(int *aa, int n) {
    static int pp[N];
    int i;
    
    for (i = 0; i < n; i++)
        pp[aa[i]] = i;
    i = n - 1;
    while (i > 0 && pp[i - 1] < pp[i])
        i--;
    return i;
}

int main() {
    static int aa[N];
    int n, i, ans2, ans3, ans4;
    long long ans1;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]), aa[i]--;
    ans1 = solve1(aa, n);
    ans2 = solve2(aa, n);
    ans3 = solve3(aa, n);
    ans4 = solve4(aa, n);
    printf("%lld %d %d %d\n", ans1, ans2, ans3, ans4);
    return 0;
}
