/*
 https://cses.fi/problemset/task/1674
 Subordinates
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int pp[N + 1], dd[N + 1], qq[N + 1], aa[N + 1];
    int n, p, i, head, cnt;
    
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &p);
        pp[i] = p;
        dd[p]++;
    }
    head = cnt = 0;
    for (i = 1; i <= n; i++)
        if (dd[i] == 0)
            qq[head + cnt++] = i;
    for (i = 1; i <= n; i++)
        aa[i] = 1;
    while (cnt) {
        i = qq[cnt--, head++];
        p = pp[i];
        aa[p] += aa[i];
        if (--dd[p] == 0)
            qq[head + cnt++] = p;
    }
    for (i = 1; i <= n; i++)
        printf("%d ", aa[i] - 1);
    printf("\n");
    return 0;
}
