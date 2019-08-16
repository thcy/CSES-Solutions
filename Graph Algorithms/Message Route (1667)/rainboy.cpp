/*
 https://cses.fi/problemset/task/1667
 Message Route
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
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

int main() {
    static int pp[N], qq[N];
    int n, m, i, j, head, cnt;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
    }
    memset(pp, -1, sizeof pp);
    head = cnt = 0;
    pp[0] = 0, qq[head + cnt++] = 0;
    while (cnt) {
        struct L *l;
        
        i = qq[cnt--, head++];
        for (l = aa[i].next; l; l = l->next)
            if (pp[j = l->j] == -1) {
                pp[j] = i, qq[head + cnt++] = j;
                if (j == n - 1) {
                    cnt = 0;
                    while (j != 0) {
                        qq[cnt++] = j + 1;
                        j = pp[j];
                    }
                    qq[cnt++] = 1;
                    printf("%d\n", cnt);
                    while (cnt--)
                        printf("%d ", qq[cnt]);
                    printf("\n");
                    return 0;
                }
            }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
