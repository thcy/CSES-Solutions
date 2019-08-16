/*
 https://cses.fi/problemset/task/1202
 Investigation
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000
#define INF    0x3f3f3f3f3f3f3f3f
#define MD    1000000007

struct L {
    struct L *next;
    int j, c;
} aa[N];

long long dd[N];
int kk[N], lmin[N], lmax[N];

struct V {
    int i;    /* for heap */
    int i_;
} vv[N], *pq[1 + N];

int cnt;

#define LT(u, v) (dd[(u)->i_] < dd[(v)->i_])

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
    int n, m, i, j, c;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &i, &j, &c), i--, j--;
        link(i, j, c);
    }
    for (i = 0; i < n; i++)
        vv[i].i_ = i;
    memset(dd, 0x3f, sizeof dd);
    dd[0] = 0;
    kk[0] = 1;
    pq_add(&vv[0]);
    while (cnt) {
        struct V *u = pq_remove_first();
        struct L *l;
        
        i = u->i_;
        for (l = aa[i].next; l; l = l->next) {
            j = l->j, c = l->c;
            if (dd[j] >= dd[i] + c) {
                int inf = dd[j] == INF;
                
                if (dd[j] > dd[i] + c) {
                    dd[j] = dd[i] + c;
                    kk[j] = kk[i];
                    lmin[j] = lmin[i] + 1;
                    lmax[j] = lmax[i] + 1;
                } else {
                    kk[j] = (kk[j] + kk[i]) % MD;
                    if (lmin[j] > lmin[i] + 1)
                        lmin[j] = lmin[i] + 1;
                    if (lmax[j] < lmax[i] + 1)
                        lmax[j] = lmax[i] + 1;
                }
                if (inf)
                    pq_add(&vv[j]);
                else
                    pq_up(&vv[j]);
            }
        }
    }
    printf("%lld %d %d %d\n", dd[n - 1], kk[n - 1], lmin[n - 1], lmax[n - 1]);
    return 0;
}
