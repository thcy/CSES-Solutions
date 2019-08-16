/*
 https://cses.fi/problemset/task/1691
 Mail Delivery
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int h;
} *aa[N];

int ij[M + 1];
char lazy[M + 1];

struct L *new_L(int h) {
    static struct L l91[M * 2 + 1 + M], *l = l91;
    
    l->h = h;
    return l++;
}

void link(int i, int h) {
    struct L *l = new_L(h);
    
    l->next = aa[i]; aa[i] = l;
}

void hierholzer(struct L *e, int i) {
    struct L *f = e->next, *l;
    
    while ((l = aa[i])) {
        int h = l->h;
        
        if (lazy[h])
            aa[i] = l->next;
        else {
            lazy[h] = 1;
            e = e->next = new_L(h);
            i ^= ij[h];
        }
    }
    e->next = f;
}

int main() {
    static int dd[N];
    struct L *e_, *e;
    int n, m, h, i, j;
    
    scanf("%d%d", &n, &m);
    for (h = 1; h <= m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        ij[h] = i ^ j;
        link(i, h), link(j, h);
        dd[i]++, dd[j]++;
    }
    for (i = 0; i < n; i++)
        if (dd[i] % 2) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    e_ = new_L(0);
    i = 0;
    m++;
    for (e = e_; e; e = e->next) {
        i ^= ij[e->h];
        hierholzer(e, i);
        m--;
    }
    if (m != 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    i = 0;
    for (e = e_; e; e = e->next) {
        i ^= ij[e->h];
        printf("%d ", i + 1);
    }
    printf("\n");
    return 0;
}
