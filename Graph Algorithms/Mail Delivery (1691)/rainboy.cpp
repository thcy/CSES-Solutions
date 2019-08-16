/*
 https://cses.fi/problemset/task/1691
 Mail Delivery
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int h;
} *aa[N + 1];

int ii[M + 1], jj[M + 1];
char removed[M + 1];

struct L *new_L(int h) {
    struct L *l = (struct L *) calloc(1, sizeof *l);
    
    l->h = h;
    return l;
}

void link(int i, int h) {
    struct L *l = new_L(h);
    
    l->next = aa[i]; aa[i] = l;
}

struct L *hierholzer(struct L *e, int i) {
    struct L *l;
    
    while ((l = aa[i])) {
        int h = l->h;
        
        if (removed[h]) {
            aa[i] = l->next;
            free(l);
        } else {
            removed[h] = 1;
            e = e->next = new_L(h);
            i ^= ii[h] ^ jj[h];
        }
    }
    return e;
}

int main() {
    static int dd[N + 1];
    struct L *e_, *e, *f;
    int n, m, h, i, j;
    
    scanf("%d%d", &n, &m);
    for (h = 1; h <= m; h++) {
        scanf("%d%d", &i, &j);
        ii[h] = i, jj[h] = j;
        link(i, h), link(j, h);
        dd[i]++, dd[j]++;
    }
    for (i = 1; i <= n; i++)
        if (dd[i] % 2) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    ii[0] = 0;
    jj[0] = 1;
    e_ = new_L(0);
    i = 0;
    m++;
    for (e = e_; e; e = e->next) {
        i ^= ii[e->h] ^ jj[e->h];
        f = e->next;
        hierholzer(e, i)->next = f;
        m--;
    }
    if (m != 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    i = 0;
    for (e = e_; e; e = e->next) {
        i ^= ii[e->h] ^ jj[e->h];
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
