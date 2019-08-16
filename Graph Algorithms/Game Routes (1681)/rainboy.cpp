/*
 https://cses.fi/problemset/task/1681
 Game Routes
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000
#define MD    1000000007

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int main() {
    static int dd[N], qq[N], dp[N];
    int n, m, i, j, head, cnt;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), dd[j]++;
    }
    head = cnt = 0;
    for (i = 0; i < n; i++)
        if (dd[i] == 0)
            qq[head + cnt++] = i;
    dp[0] = 1;
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        for (l = aa[i].next; l; l = l->next) {
            j = l->j;
            if (--dd[j] == 0)
                qq[head + cnt++] = j;
            dp[j] = (dp[j] + dp[i]) % MD;
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}
