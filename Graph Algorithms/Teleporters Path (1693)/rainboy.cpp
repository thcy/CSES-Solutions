/*
 https://cses.fi/problemset/task/1693
 Teleporters Path
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} *aa[N];

struct L *new_L(int j) {
    static struct L l91[M + 1 + M], *l = l91;
    
    l->j = j;
    return l++;
}

void link(int i, int j) {
    struct L *l = new_L(j);
    
    l->next = aa[i]; aa[i] = l;
}

void hierholzer(struct L *e) {
    struct L *f = e->next, *l;
    int i = e->j;
    
    while ((l = aa[i])) {
        aa[i] = l->next;
        e = e->next = new_L(l->j);
        i = l->j;
    }
    e->next = f;
}

int main() {
    static int din[N], dout[N];
    struct L *e_, *e;
    int n, m, h, i, j;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
        dout[i]++, din[j]++;
    }
    if (dout[0] - din[0] != 1 || din[n - 1] - dout[n - 1] != 1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (i = 1; i < n - 1; i++)
        if (dout[i] != din[i]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    e_ = new_L(0);
    m++;
    hierholzer(e_);
    for (e = e_; e; e = e->next) {
        hierholzer(e);
        m--;
    }
    if (m != 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (e = e_; e; e = e->next)
        printf("%d ", e->j + 1);
    printf("\n");
    return 0;
}
