/*
 https://cses.fi/problemset/task/1692
 De Bruijn Sequence
 practice with Dukkha
 */
#include <stdio.h>

#define K    15
#define N    (1 << (K - 1))

struct L {
    struct L *next;
    int v;
};

struct L *new_L(int v) {
    static struct L l91[1 + N * 2], *l = l91;
    
    l->v = v;
    return l++;
}

char hh[N];
int mask;

void hierholzer(struct L *e) {
    struct L *f = e->next;
    int v = e->v;
    
    while (hh[v] < 2) {
        v = (v << 1 | hh[v]++) & mask;
        e = e->next = new_L(v);
    }
    e->next = f;
}

int main() {
    static char aa[K - 1 + (1 << K) + 1];
    struct L *e, *e_;
    int k, i;
    
    scanf("%d", &k);
    if (k == 1) {
        printf("01\n");
        return 0;
    }
    mask = (1 << (k - 1)) - 1;
    e_ = new_L(0);
    i = 0;
    while (i < k - 2)
        aa[i++] = '0';
    for (e = e_; e; e = e->next) {
        aa[i++] = '0' + (e->v & 1);
        hierholzer(e);
    }
    printf("%s\n", aa);
    return 0;
}
