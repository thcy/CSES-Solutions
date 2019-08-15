// https://cses.fi/problemset/task/1077
// Sliding Cost
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000, M = 524288;
int aa[N], ii[N], bb[N], cnt[M];
long long sum[M];
int i_, x_;

void update(int k, int l, int r) {
    cnt[k] += x_;
    sum[k] += x_ * bb[i_];
    if (r - l > 1) {
        int m = (l + r) / 2;
        if (i_ < m)
            update(k * 2 + 1, l, m);
        else
            update(k * 2 + 2, m, r);
    }
}

long long s;
int query(int k, int l, int r, int x) {
    if (r - l == 1) {
        s += (long long) x * bb[l];
        return l;
    }
    int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    if (cnt[k1] >= x)
        return query(k1, l, m, x);
    else {
        s += sum[k1];
        return query(k2, m, r, x - cnt[k1]);
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
        ii[i] = i;
    }
    sort(ii, ii + n, [] (int i, int j) { return aa[i] < aa[j]; });
    int n_ = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || aa[ii[i - 1]] != aa[ii[i]])
            bb[n_++] = aa[ii[i]];
        aa[ii[i]] = n_ - 1;
    }
    int m = 1;
    while (m < n_)
        m *= 2;
    int h = (k + 1) / 2;
    for (int i = 0; i < n; i++) {
        i_ = aa[i]; x_ = 1;
        update(0, 0, m);
        if (i >= k) {
            i_ = aa[i - k]; x_ = -1;
            update(0, 0, m);
        }
        if (i >= k - 1) {
            s = 0;
            int j = query(0, 0, m, h);
            // (h * bb[j] - s) + (sum[0] - s - (k - h) * bb[j]);
            long long ans = sum[0] - s * 2 + k % 2 * bb[j];
            printf("%lld ", ans);
        }
    }
    printf("\n");
}
