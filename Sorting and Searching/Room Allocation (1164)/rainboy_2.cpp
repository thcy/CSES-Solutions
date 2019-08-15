/*
 https://cses.fi/problemset/task/1164
 Room Allocation
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

int aa[N], bb[N], *stack = aa, *cc = bb;

struct V {
    int i, x;
} vv[N * 2];

int compare(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->x - v->x;
}

int main() {
    int n, h, i, lr, k, cnt;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &aa[i], &bb[i]), bb[i]++;
    for (i = 0; i < n; i++)
        for (lr = 0; lr <= 1; lr++) {
            struct V *u = &vv[i * 2 + lr];
            
            u->i = i, u->x = (lr == 0 ? aa : bb)[i] * 2 + 1 - lr;
        }
    qsort(vv, n * 2, sizeof *vv, compare);
    cnt = 0, k = 0;
    for (h = 0; h < n * 2; h++) {
        struct V *u = &vv[h];
        
        if (u->x % 2 == 1)
            cc[u->i] = cnt == 0 ? ++k : stack[--cnt];
        else
            stack[cnt++] = cc[u->i];
    }
    printf("%d\n", k);
    for (i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
