/*
 https://cses.fi/problemset/task/1705/
 Forbidden Cities
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000
#define N_    (N * 2 * 2)
#define INF    0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int dsu[M + N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

int join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return 0;
    if (dsu[i] > dsu[j])
        dsu[i] = j;
    else {
        if (dsu[i] == dsu[j])
            dsu[i]--;
        dsu[j] = i;
    }
    return 1;
}

int ta[N], tb[N], tc[M + N], time;

struct L {
    struct L *next;
    int x;
} aa[N], aa_[M + N];

int ii[M], jj[M], hh[N];
char cut[N];

void link(int i, int h) {
    static struct L l91[M * 2], *l = l91;
    
    l->x = h;
    l->next = aa[i].next, aa[i].next = l++;
}

void link_(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->x = j;
    l->next = aa_[i].next, aa_[i].next = l++;
}

void dfs1(int h_, int i) {
    struct L *l;
    int c, h, j;
    
    hh[i] = h_;
    ta[i] = tb[i] = ++time;
    c = 0;
    for (l = aa[i].next; l; l = l->next)
        if ((h = l->x) != h_) {
            j = i ^ ii[h] ^ jj[h];
            if (!ta[j]) {
                c++;
                dfs1(h, j);
                tb[i] = min(tb[i], tb[j]);
                if (h_ != -1 && ta[i] <= tb[j])
                    cut[i] = 1;
            } else if (ta[j] < ta[i])
                tb[i] = min(tb[i], ta[j]);
        }
    if (h_ == -1 && c > 1)
        cut[i] = 1;
}

void dfs2(int h_, int i) {
    struct L *l;
    int h, j;
    
    for (l = aa[i].next; l; l = l->next)
        if ((h = l->x) != h_) {
            j = i ^ ii[h] ^ jj[h];
            if (hh[j] != h && ta[j] > ta[i])
                while (j != i) {
                    if (!join(h, hh[j]))
                        break;
                    h = hh[j];
                    j ^= ii[h] ^ jj[h];
                }
        }
    for (l = aa[i].next; l; l = l->next)
        if ((h = l->x) != h_) {
            j = i ^ ii[h] ^ jj[h];
            if (hh[j] == h)
                dfs2(h, j);
        }
}

int tr[N_ * 2 + 1], n_, i_;

void update(int k, int x) {
    for (k += n_; k >= 1; k >>= 1)
        tr[k] = min(tr[k], x);
}

int query(int l, int r) {
    int x = INF;
    
    for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1) {
        if ((l & 1) == 1)
            x = min(x, tr[l++]);
        if ((r & 1) == 0)
            x = min(x, tr[r--]);
    }
    return x;
}

int ll[M + N], rr[M + N];

void dfs_(int i) {
    struct L *l;
    int j;
    
    tc[i] = ++time;
    ll[i] = i_;
    update(i_++, tc[i]);
    for (l = aa_[i].next; l; l = l->next)
        if (tc[j = l->x] == 0) {
            dfs_(j);
            update(i_++, tc[i]);
        }
    rr[i] = i_;
}

int ancestor(int i, int a) {
    return ll[a] <= ll[i] && rr[i] <= rr[a];
}

int block(int i, int j, int k) {
    int aik, ajk;
    
    if (ll[i] > ll[j])
        return block(j, i, k);
    aik = ancestor(i, k);
    ajk = ancestor(j, k);
    return aik != ajk || aik && ajk && query(ll[i], ll[j]) == tc[k];
}

int main() {
    int n, m, q, h, h_, i, j, k;
    
    scanf("%d%d%d", &n, &m, &q);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        ii[h] = i, jj[h] = j;
        link(i, h), link(j, h);
    }
    dfs1(-1, 0);
    memset(dsu, -1, (m + n) * sizeof *dsu);
    dfs2(-1, 0);
    for (h = 0; h < m; h++) {
        i = ii[h], j = jj[h];
        if (!cut[i])
            join(h, m + i);
        if (!cut[j])
            join(h, m + j);
    }
    for (i = 0; i < n; i++)
        if (cut[i]) {
            struct L *l;
            
            for (l = aa[i].next; l; l = l->next) {
                h = find(l->x);
                link_(m + i, h);
                link_(h, m + i);
            }
        }
    h_ = 0;
    for (h = 0; h < m + n; h++)
        if (aa_[h].next) {
            n_++;
            h_ = h;
        }
    n_ *= 2;
    memset(tr, 0x3f, (n_ * 2 + 1) * sizeof *tr);
    time = 0;
    dfs_(h_);
    while (q--) {
        int yes;
        
        scanf("%d%d%d", &i, &j, &k), i--, j--, k--;
        if (i == k || j == k)
            yes = 0;
        else if (!cut[k])
            yes = 1;
        else
            yes = !block(find(m + i), find(m + j), find(m + k));
        printf(yes ? "YES\n" : "NO\n");
    }
    return 0;
}
