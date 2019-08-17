/*
 https://cses.fi/problemset/task/1701
 Tree Isomorphism II
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    100000
#define MD    1000000007

struct L {
    struct L *next;
    int j;
} aa[N];

int xx[N], yy[N], xx_[N], yy_[N], hh[N], jj[N];

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

void init_rand() {
    struct timeval tv;
    int h;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
    xx[0] = 1;
    for (h = 1; h < N - 1; h++)
        xx[h] = rand_(MD - 2) + 2;
    yy[0] = 1;
    for (h = 1; h < N - 1; h++)
        yy[h] = rand_(MD - 2) + 2;
}

void link(int i, int j) {
    static struct L l91[N * 2 * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

void dfs(int p, int i) {
    struct L *l;
    int h, j, x, y, x_, y_;
    
    h = -1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            dfs(i, j);
            if (h < hh[j])
                h = hh[j];
        }
    hh[i] = ++h;
    x = xx[h], y = yy[h], x_ = 1, y_ = 1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            x_ = (long long) x_ * (x + xx_[j]) % MD;
            y_ = (long long) y_ * (y + yy_[j]) % MD;
        }
    xx_[i] = x_, yy_[i] = y_;
}

void dfs2(int p, int i, int hp, int xp, int yp) {
    struct L *l;
    int *px, *py, *qx, *qy, *jj, h1, h2, a, j, j1, c, x, y, x_, y_, xi, yi;
    
    c = 0;
    for (l = aa[i].next; l; l = l->next)
        if (l->j != p)
            c++;
    jj = (int *) malloc(c * sizeof *jj);
    c = 0;
    h1 = -1, h2 = -1, j1 = -1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            if (h1 < hh[j]) {
                h2 = h1, h1 = hh[j];
                j1 = j;
            } else if (h2 < hh[j])
                h2 = hh[j];
            jj[c++] = j;
        }
    h1 = (h1 > hp ? h1 : hp) + 1;
    h2 = (h2 > hp ? h2 : hp) + 1;
    px = (int *) malloc(c * sizeof *px);
    py = (int *) malloc(c * sizeof *py);
    x = xx[h1], y = yy[h1];
    x_ = y_ = 1;
    if (hp != -1) {
        x_ = (long long) x_ * (x + xp) % MD;
        y_ = (long long) y_ * (y + yp) % MD;
    }
    for (a = 0; a < c; a++) {
        px[a] = x_;
        py[a] = y_;
        j = jj[a];
        x_ = (long long) x_ * (x + xx_[j]) % MD;
        y_ = (long long) y_ * (y + yy_[j]) % MD;
    }
    xi = x_, yi = y_;
    qx = (int *) malloc(c * sizeof *qx);
    qy = (int *) malloc(c * sizeof *qy);
    x_ = y_ = 1;
    for (a = c - 1; a >= 0; a--) {
        qx[a] = x_;
        qy[a] = y_;
        j = jj[a];
        x_ = (long long) x_ * (x + xx_[j]) % MD;
        y_ = (long long) y_ * (y + yy_[j]) % MD;
    }
    if (j1 != -1) {
        x = xx[h2], y = yy[h2];
        x_ = y_ = 1;
        if (hp != -1) {
            x_ = (long long) x_ * (x + xp) % MD;
            y_ = (long long) y_ * (y + yp) % MD;
        }
        for (a = 0; a < c; a++) {
            j = jj[a];
            if (j != j1) {
                x_ = (long long) x_ * (x + xx_[j]) % MD;
                y_ = (long long) y_ * (y + yy_[j]) % MD;
            }
        }
        dfs2(i, j1, h2, x_, y_);
    }
    for (a = 0; a < c; a++) {
        j = jj[a];
        if (j != j1) {
            x_ = (long long) px[a] * qx[a] % MD;
            y_ = (long long) py[a] * qy[a] % MD;
            dfs2(i, j, h1, x_, y_);
        }
    }
    xx_[i] = xi, yy_[i] = yi;
}

int main() {
    int t;
    
    init_rand();
    scanf("%d", &t);
    while (t--) {
        int n, h, i, j, k, yes;
        long long z;
        
        scanf("%d", &n);
        for (k = 0; k < 2; k++) {
            for (i = 0; i < n; i++)
                aa[i].next = NULL;
            for (h = 0; h < n - 1; h++) {
                scanf("%d%d", &i, &j), i--, j--;
                link(i, j);
                link(j, i);
            }
            dfs(-1, 0);
            if (k == 0) {
                z = (long long) xx_[0] * MD + yy_[0];
                continue;
            }
            dfs2(-1, 0, -1, -1, -1);
        }
        yes = 0;
        for (i = 0; i < n; i++)
            if (z == (long long) xx_[i] * MD + yy_[i]) {
                yes = 1;
                break;
            }
        printf(yes ? "YES\n" : "NO\n");
    }
    return 0;
}
