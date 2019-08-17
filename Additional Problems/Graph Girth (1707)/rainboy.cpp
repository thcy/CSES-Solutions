/*
 https://cses.fi/problemset/task/1707
 Graph Girth
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    2500
#define M    5000
#define INF    0x3f3f3f3f

struct L {
    struct L *next;
    int j;
} aa[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next; aa[i].next = l++;
}

int bfs(int i) {
    static int qq[N], dd[N];
    struct L *l;
    int j, d, d_, head, cnt;
    
    memset(dd, 0x3f, sizeof dd);
    d_ = INF;
    head = cnt = 0;
    dd[i] = 0;
    qq[head + cnt++] = i;
    while (cnt) {
        i = qq[cnt--, head++];
        d = dd[i];
        if (d > d_)
            return d_ * 2 + 2;
        for (l = aa[i].next; l; l = l->next) {
            j = l->j;
            if (dd[j] < d)
                continue;
            if (dd[j] == INF) {
                dd[j] = d + 1;
                qq[head + cnt++] = j;
            } else {
                if (dd[j] == d)
                    return d * 2 + 1;
                d_ = d;
            }
        }
    }
    return INF + 1;
}

int main() {
    int n, m, h, i, j, ans, c;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j), link(j, i);
        if (i == j) {
            printf("1\n");
            return 0;
        }
    }
    ans = INF;
    for (i = 0; i < n; i++)
        if (ans > (c = bfs(i)))
            ans = c;
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
