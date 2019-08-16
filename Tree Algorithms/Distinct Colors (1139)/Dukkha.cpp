// https://cses.fi/problemset/task/1139
// Distinct Colors
// practice with rainboy
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 500000;

vector<int> aa[N];

int cc[N], ii[N], jj[N], ll[N], rr[N], tt[N];

void dfs(int p, int i) {
    static int t;
    ll[i] = t++;
    for (int j : aa[i])
        if (j != p)
            dfs(i, j);
    rr[i] = t;
}

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int cnt = 0;
    while (i >= 0) {
        cnt += tt[i];
        i &= i + 1;
        i--;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cc[i]);
        ii[i] = i;
    }
    sort(ii, ii + n, [] (int i, int j) { return cc[i] < cc[j]; });
    int m = 0;
    for (int i = 0; i < n; i++)
        cc[ii[i]] = i + 1 == n || cc[ii[i]] != cc[ii[i + 1]] ? m++ : m;
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs(-1, 0);
    sort(ii, ii + n, [] (int i, int j) { return ll[i] > ll[j]; });
    fill_n(jj, m, -1);
    for (int i_ = 0; i_ < n; i_++) {
        int i = ii[i_], c = cc[i], j = jj[c];
        if (j != -1)
            update(ll[j], n, -1);
        update(ll[i], n, 1);
        jj[c] = i;
        cc[i] = query(rr[i] - 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
