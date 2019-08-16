/*
 https://cses.fi/problemset/task/1196
 Flight Routes
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000
#define K    10
#define INF    0x3f3f3f3f3f3f3f3fLL

struct L {
    struct L *next;
    int j, c;
} aa[N];

struct V {
    int i;    /* for heap */
    int i_, h_;
} vv[N][K], *pq[1 + N * K];

long long dd[N][K];

int cnt;

#define LT(u, v) (dd[(u)->i_][(u)->h_] < dd[(v)->i_][(v)->h_])

int i2(int i) {
    return (i *= 2) > cnt ? 0 : i < cnt && LT(pq[i + 1], pq[i]) ? i + 1 : i;
}

void pq_up(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i / 2) && LT(u, pq[j]); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_dn(struct V *u) {
    int i, j;
    
    for (i = u->i; (j = i2(i)) && LT(pq[j], u); i = j)
        pq[pq[j]->i = i] = pq[j];
    pq[u->i = i] = u;
}

void pq_add(struct V *u) {
    u->i = ++cnt;
    pq_up(u);
}

struct V *pq_remove_first() {
    struct V *u = pq[1], *v = pq[cnt--];
    
    v->i = 1;
    pq_dn(v);
    return u;
}

void link(int i, int j, int c) {
    static struct L l91[M], *l = l91;
    
    l->j = j, l->c = c;
    l->next = aa[i].next; aa[i].next = l++;
}

int main() {
    int n, m, k, h, h_, i, i_, j, c;
    long long d;
    
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        link(i, j, c);
    }
    for (i = 0; i < n; i++)
        for (h = 0; h < k; h++) {
            struct V *u = &vv[i][h];
            
            u->i_ = i, u->h_ = h;
        }
    memset(dd, 0x3f, sizeof dd);
    dd[0][0] = 0;
    pq_add(&vv[0][0]);
    while (cnt) {
        struct V *u = pq_remove_first();
        struct L *l;
        
        i = u->i_, h = u->h_;
        d = dd[i][h];
        for (l = aa[i].next; l; l = l->next) {
            i_ = l->j, c = l->c;
            for (h_ = 0; h_ < k; h_++)
                if (dd[i_][h_] > d + c) {
                    long long d1 = d + c;
                    
                    while (h_ < k && d1 != INF) {
                        long long d2 = dd[i_][h_];
                        
                        dd[i_][h_] = d1;
                        if (d2 == INF)
                            pq_add(&vv[i_][h_]);
                        else
                            pq_up(&vv[i_][h_]);
                        d1 = d2;
                        h_++;
                    }
                    break;
                }
        }
    }
    for (h = 0; h < k; h++)
        printf("%lld ", dd[n - 1][h]);
    printf("\n");
    return 0;
}
