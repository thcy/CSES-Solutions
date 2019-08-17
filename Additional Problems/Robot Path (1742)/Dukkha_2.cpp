// https://cses.fi/problemset/task/1742
// Robot Path
// practice with rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000, INF = 0x3f3f3f3f;

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

struct V {
    int y, l, r;
} vv[N * 2];

int xl[N], xr[N], yd[N], yu[N];

bool check(int n) {
    int bound = n - 1;
    int n_ = 0;
    for (int i = 0; i < n; i++)
        if (xl[i] != xr[i])
            vv[n_++] = { yd[i], xl[i], xr[i] };
        else {
            vv[n_++] = { yd[i], xl[i], -INF };
            vv[n_++] = { yu[i], xl[i], INF };
        }
    n = n_;
    sort(vv, vv + n, [] (auto &u, auto &v) { return u.y < v.y || u.y == v.y && u.r < v.r; });
    fill_n(tt, nt, 0);
    int r = -INF;
    for (int i = 0; i < n; i++) {
        auto &v = vv[i];
        if (i > 0 && vv[i - 1].y != vv[i].y)
            r = -INF;
        if (v.r == -INF) {
            if (query(v.l) - query(v.l - 1) != 0)
                return false;
            update(v.l, 1);
        } else if (v.r == INF) {
            update(v.l, -1);
        } else {
            if (r >= v.l)
                return false;
            bound -= query(v.r) - query(v.l - 1);
            if (bound < 0)
                return false;
            r = v.r;
        }
    }
    return true;
}

bool opposite(char a, char b) {
    return a == 'L' && b == 'R' || a == 'R' && b == 'L' || a == 'D' && b == 'U' || a == 'U' && b == 'D';
}

int main() {
    static long long xx_[N + 1], yy_[N + 1];
    int n;
    scanf("%d", &n);
    long long x_, y_;
    xx_[0] = x_ = 0;
    yy_[0] = y_ = 0;
    char dir_ = ' ';
    int n_ = 1;
    for (int i = 0; i < n; i++) {
        char s[2];
        int z;
        scanf("%s%d", s, &z);
        char dir = s[0];
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
    static int xx[N + 1], yy[N + 1], ii[N + 1];
    for (int i = 0; i <= n; i++)
        ii[i] = i;
    sort(ii, ii + n + 1, [] (int i, int j) { return xx_[i] < xx_[j]; });
    for (int h = 0, x = 0; h <= n; h++)
        xx[ii[h]] = h == n || xx_[ii[h]] != xx_[ii[h + 1]] ? x++ : x;
    sort(ii, ii + n + 1, [] (int i, int j) { return yy_[i] < yy_[j]; });
    for (int h = 0, y = 0; h <= n; h++)
        yy[ii[h]] = h == n || yy_[ii[h]] != yy_[ii[h + 1]] ? y++ : y;
    for (int i = 0; i < n; i++) {
        xl[i] = xx[i]; xr[i] = xx[i + 1];
        if (xl[i] > xr[i]) { swap(xl[i], xr[i]); }
        yd[i] = yy[i]; yu[i] = yy[i + 1];
        if (yd[i] > yu[i]) { swap(yd[i], yu[i]); }
    }
    nt = n + 1;
    int lower = 0, upper = n;
    while (upper - lower > 1) {
        n_ = (lower + upper) / 2;
        if (!check(n_))
            upper = n_;
        else
            lower = n_;
    }
    int j = upper - 1;
    x_ = xx_[j];
    y_ = yy_[j];
    static long long xl_[N], xr_[N], yd_[N], yu_[N];
    for (int i = 0; i < n; i++) {
        xl_[i] = xx_[i]; xr_[i] = xx_[i + 1];
        if (xl_[i] > xr_[i]) { swap(xl_[i], xr_[i]); }
        yd_[i] = yy_[i]; yu_[i] = yy_[i + 1];
        if (yd_[i] > yu_[i]) { swap(yd_[i], yu_[i]); }
    }
    long long w = 0, wj = xr_[j] - xl_[j] + yu_[j] - yd_[j];
    for (int i = 0; i < j; i++) {
        w += xr_[i] - xl_[i] + yu_[i] - yd_[i];
        if (i < j - 1) {
            long long l = max(xl_[i], xl_[j]);
            long long r = min(xr_[i], xr_[j]);
            if (l > r)
                continue;
            long long d = max(yd_[i], yd_[j]);
            long long u = min(yu_[i], yu_[j]);
            if (d > u)
                continue;
            wj = min(wj, abs(l - x_) + abs(d - y_));
            wj = min(wj, abs(r - x_) + abs(u - y_));
        }
    }
    w += wj;
    printf("%lld\n", w);
    return 0;
}
