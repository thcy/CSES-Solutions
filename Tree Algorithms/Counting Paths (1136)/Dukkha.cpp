// https://cses.fi/problemset/task/1136
// Counting Paths
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 200000, K = 17;

vector<int> aa[N];

int pp[N][K + 1], dd[N], ll[N], rr[N], cc[N];

void dfs1(int p, int i, int d) {
    dd[i] = d;
    pp[i][0] = p;
    for (int k = 1; 1 << k <= d; k++)
        pp[i][k] = pp[pp[i][k - 1]][k - 1];
    for (int j : aa[i])
        if (j != p)
            dfs1(i, j, d + 1);
}

int dfs2(int p, int i) {
    int c = cc[i];
    for (int j : aa[i])
        if (j != p)
            c += dfs2(i, j);
    cc[i] = c += ll[i];
    return c - rr[i];
}

int lca(int i, int j) {
    if (dd[i] < dd[j])
        return lca(j, i);
    for (int k = K; k >= 0; k--)
        if (1 << k <= dd[i] - dd[j])
            i = pp[i][k];
    if (i == j)
        return i;
    for (int k = K; k >= 0; k--)
        if (1 << k <= dd[i] && pp[i][k] != pp[j][k]) {
            i = pp[i][k];
            j = pp[j][k];
        }
    return pp[i][0];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs1(-1, 0, 0);
    while (m--) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        int a = lca(i, j);
        if (i == a) {
            ll[j]++;
            rr[i]++;
        } else if (j == a) {
            ll[i]++;
            rr[j]++;
        } else {
            ll[i]++;
            ll[j]++;
            rr[a]++;
            cc[a]--;
        }
    }
    dfs2(-1, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
    return 0;
}
