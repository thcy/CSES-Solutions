/*
 https://cses.fi/problemset/task/1685
 New Flight Routes
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    200000

struct L {
    struct L *next;
    int j;
} aa[N], bb[N], aa_[N];

void link(int i, int j) {
    static struct L l91[M * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next, bb[j].next = l++;
}

void link_(int i, int j) {
    static struct L l91[M], *l = l91;
    
    l->j = j;
    l->next = aa_[i].next, aa_[i].next = l++;
}

int po[N], npo;
char visited[N];

void dfs1(int i) {
    struct L *l;
    
    if (visited[i])
        return;
    visited[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        dfs1(l->j);
    po[npo++] = i;
}

int cc[N], dd[N];

void dfs2(int j, int c) {
    struct L *l;
    int c_ = cc[j];
    
    if (c_ != -1) {
        if (c_ != c) {
            link_(c_, c);
            dd[c]++;
        }
        return;
    }
    cc[j] = c;
    for (l = bb[j].next; l; l = l->next)
        dfs2(l->j, c);
}

int dfs3(int i) {
    struct L *l;
    
    if (visited[i])
        return -1;
    visited[i] = 1;
    if (!aa_[i].next)
        return i;
    for (l = aa_[i].next; l; l = l->next) {
        int w = dfs3(l->j);
        
        if (w != -1)
            return w;
    }
    return -1;
}

void add(int i, int j) {
    printf("%d %d\n", i + 1, j + 1);
}

void augment(int n) {
    static int vv[N], ww[N];
    static char iv[N], iw[N];
    int h, i, p, q, s, t, x;
    
    p = 0;
    for (i = 0; i < n; i++) {
        if (cc[i] != i)
            continue;
        if (dd[i] == 0) {
            int w = dfs3(i);
            
            if (w != -1) {
                iv[vv[p] = i] = 1;
                iw[ww[p] = w] = 1;
                p++;
            }
        }
    }
    s = t = p;
    for (i = 0; i < n; i++) {
        if (cc[i] != i)
            continue;
        if (!iv[i] && dd[i] == 0)
            vv[s++] = i;
        if (!iw[i] && !aa_[i].next)
            ww[t++] = i;
    }
    printf("%d\n", s > t ? s : t);
    for (h = 0; h < p - 1; h++)
        add(ww[h], vv[h + 1]);
    q = s < t ? s : t;
    for (h = p; h < q; h++)
        add(ww[h], vv[h]);
    x = ww[p - 1];
    for (h = q; h < s; h++)
        add(x, vv[h]), x = vv[h];
    for (h = q; h < t; h++)
        add(x, ww[h]), x = ww[h];
    add(x, vv[0]);
}

int main() {
    int n, m, h, i, j, k;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        link(i, j);
    }
    for (i = 0; i < n; i++)
        dfs1(i);
    memset(cc, -1, n * sizeof *cc);
    k = 0;
    for (h = n - 1; h >= 0; h--) {
        j = po[h];
        if (cc[j] == -1) {
            dfs2(j, j);
            k++;
        }
    }
    if (k == 1) {
        printf("0\n");
        return 0;
    }
    memset(visited, 0, n * sizeof *visited);
    augment(n);
    return 0;
}
