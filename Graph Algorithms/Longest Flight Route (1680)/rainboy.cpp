/*
 https://cses.fi/problemset/task/1680
 Longest Flight Route
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

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
    static int dd[N], qq[N], dp[N], pp[N];
    int n, m, h, i, j, k, head, cnt;
    
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
            if (dp[i] != 0 && dp[j] < dp[i] + 1) {
                dp[j] = dp[i] + 1;
                pp[j] = i;
            }
        }
    }
    k = dp[n - 1];
    if (k == 0)
        printf("IMPOSSIBLE\n");
    else {
        for (h = k - 1, i = n - 1; h >= 0; h--, i = pp[i])
            qq[h] = i;
        printf("%d\n", k);
        for (h = 0; h < k; h++)
            printf("%d ", qq[h] + 1);
        printf("\n");
    }
    return 0;
}
