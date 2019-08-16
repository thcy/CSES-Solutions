// https://cses.fi/problemset/task/1137
// Subtree Queries
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 200000;

vector<int> aa[N];

int xx[N], ll[N], rr[N];
long long tt[N];

void dfs(int p, int i) {
    static int t;
    ll[i] = t++;
    for (int j : aa[i])
        if (j != p)
            dfs(i, j);
    rr[i] = t;
}

void update(int i, int n, long long x) {
    while (i < n) {
        tt[i] += x;
        i |= i + 1;
    }
}

long long query(int i) {
    long long sum = 0;
    while (i >= 0) {
        sum += tt[i];
        i &= i + 1;
        i--;
    }
    return sum;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &xx[i]);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs(-1, 0);
    for (int i = 0; i < n; i++)
        update(ll[i], n, xx[i]);
    while (q--) {
        int t, i, x;
        scanf("%d%d", &t, &i);
        i--;
        if (t == 1) {
            scanf("%d", &x);
            update(ll[i], n, x - xx[i]);
            xx[i] = x;
        } else
            printf("%lld\n", query(rr[i] - 1) - query(ll[i] - 1));
    }
    return 0;
}
