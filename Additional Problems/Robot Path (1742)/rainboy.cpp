/*
 https://cses.fi/problemset/task/1742
 Robot Path
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N    100000
#define INF    0x3f3f3f3f

long long ab(long long a) { return a < 0 ? -a : a; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
int signum(long long x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

int tt[N + 1], nt;

void update(int i, int x) {
    while (i < nt) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    
    while (i >= 0) {
        x += tt[i];
        i &= i + 1;
        i--;
    }
    return x;
}

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

int xl[N], xr[N], yd[N], yu[N];
long long xx_[N + 1], yy_[N + 1];
int xx[N + 1], yy[N + 1];

struct V {
    int y, l, r;
} vv[N * 2];

int compare_x(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return signum(xx_[i] - xx_[j]);
}

int compare_y(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return signum(yy_[i] - yy_[j]);
}

int compare_yr(const void *a, const void *b) {
    struct V *u = (struct V *) a;
    struct V *v = (struct V *) b;
    
    return u->y != v->y ? u->y - v->y : u->r - v->r;
}

void shuffle(int *aa, int n) {
    int i, j, tmp;
    
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
    }
}

void shuffle_(struct V *aa, int n) {
    int i, j;
    struct V tmp;
    
    for (j = 0; j < n; j++) {
        i = rand_(j + 1);
        tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
    }
}

long long check(int n) {
    int n_, i, r, bound;
    struct V *v;
    
    bound = n - 1;
    n_ = 0;
    for (i = 0; i < n; i++)
        if (xl[i] != xr[i]) {
            v = &vv[n_++];
            v->y = yd[i], v->l = xl[i], v->r = xr[i];
        } else {
            v = &vv[n_++];
            v->y = yd[i], v->l = xl[i], v->r = -INF;
            v = &vv[n_++];
            v->y = yu[i], v->l = xl[i], v->r = INF;
        }
    n = n_;
    shuffle_(vv, n), qsort(vv, n, sizeof *vv, compare_yr);
    memset(tt, 0, nt * sizeof *tt);
    r = -INF;
    for (i = 0; i < n; i++) {
        struct V *v = &vv[i];
        
        if (i > 0 && vv[i - 1].y != vv[i].y)
            r = -INF;
        if (v->r == -INF) {
            if (query(v->l) - query(v->l - 1) != 0)
                return 0;
            update(v->l, 1);
        } else if (v->r == INF) {
            update(v->l, -1);
        } else {
            if (r >= v->l)
                return 0;
            bound -= query(v->r) - query(v->l - 1);
            if (bound < 0)
                return 0;
            r = v->r;
        }
    }
    return 1;
}

int opposite(char a, char b) {
    return a == 'L' && b == 'R' || a == 'R' && b == 'L' || a == 'D' && b == 'U' || a == 'U' && b == 'D';
}

int main() {
    static long long xl_[N], xr_[N], yd_[N], yu_[N];
    static int ii[N + 1];
    int n, n_, h, i, j, x, y, lower, upper;
    long long x_, y_, w, wj, l, r, u, d;
    char dir_;
    
    scanf("%d\n", &n);
    xx_[0] = x_ = 0;
    yy_[0] = y_ = 0;
    dir_ = ' ';
    n_ = 1;
    for (i = 0; i < n; i++) {
        char dir;
        int z;
        
        scanf("%c %d\n", &dir, &z);
        if (opposite(dir, dir_))
            break;
        if (dir == 'L')
            x_ -= z;
        else if (dir == 'R')
            x_ += z;
        else if (dir == 'D')
            y_ -= z;
        else
            y_ += z;
        if (dir_ != dir) {
            dir_ = dir;
            n_++;
        }
        xx_[n_ - 1] = x_;
        yy_[n_ - 1] = y_;
    }
    n = n_ - 1;
    for (i = 0; i <= n; i++)
        ii[i] = i;
    shuffle(ii, n + 1), qsort(ii, n + 1, sizeof *ii, compare_x);
    for (h = 0, x = 0; h <= n; h++)
        xx[ii[h]] = h == n || xx_[ii[h]] != xx_[ii[h + 1]] ? x++ : x;
    shuffle(ii, n + 1), qsort(ii, n + 1, sizeof *ii, compare_y);
    for (h = 0, y = 0; h <= n; h++)
        yy[ii[h]] = h == n || yy_[ii[h]] != yy_[ii[h + 1]] ? y++ : y;
    for (i = 0; i < n; i++) {
        int tmp;
        
        xl[i] = xx[i], xr[i] = xx[i + 1];
        if (xl[i] > xr[i]) tmp = xl[i], xl[i] = xr[i], xr[i] = tmp;
        yd[i] = yy[i], yu[i] = yy[i + 1];
        if (yd[i] > yu[i]) tmp = yd[i], yd[i] = yu[i], yu[i] = tmp;
    }
    nt = n + 1;
    lower = 0, upper = n;
    while (upper - lower > 1) {
        n_ = (lower + upper) / 2;
        if (!check(n_))
            upper = n_;
        else
            lower = n_;
    }
    j = upper - 1;
    x_ = xx_[j];
    y_ = yy_[j];
    for (i = 0; i < n; i++) {
        long long tmp;
        
        xl_[i] = xx_[i], xr_[i] = xx_[i + 1];
        if (xl_[i] > xr_[i]) tmp = xl_[i], xl_[i] = xr_[i], xr_[i] = tmp;
        yd_[i] = yy_[i], yu_[i] = yy_[i + 1];
        if (yd_[i] > yu_[i]) tmp = yd_[i], yd_[i] = yu_[i], yu_[i] = tmp;
    }
    w = 0, wj = xr_[j] - xl_[j] + yu_[j] - yd_[j];
    for (i = 0; i < j; i++) {
        w += xr_[i] - xl_[i] + yu_[i] - yd_[i];
        if (i < j - 1) {
            l = max(xl_[i], xl_[j]), r = min(xr_[i], xr_[j]);
            if (l > r)
                continue;
            d = max(yd_[i], yd_[j]), u = min(yu_[i], yu_[j]);
            if (d > u)
                continue;
            wj = min(wj, min(ab(l - x_) + ab(d - y_), ab(r - x_) + ab(u - y_)));
        }
    }
    w += wj;
    printf("%lld\n", w);
    return 0;
}
