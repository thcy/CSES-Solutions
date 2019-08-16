/*
 https://cses.fi/problemset/task/1679
 Course Schedule
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N];

int dd[N];

void link(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int main() {
    static int qq[N];
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
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        for (l = aa[i].next; l; l = l->next)
            if (--dd[j = l->j] == 0)
                qq[head + cnt++] = j;
    }
    if (head == n)
        for (i = 0; i < n; i++)
            printf("%d ", qq[i] + 1);
    else
        printf("IMPOSSIBLE");
    printf("\n");
    return 0;
}
