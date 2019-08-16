// https://cses.fi/problemset/task/1135
// Distance Queries
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 200000, K = 17;

vector<int> aa[N];
int dd[N];
int pp[N][K + 1];

void dfs(int p, int i, int d) {
    dd[i] = d;
    pp[i][0] = p;
    for (int k = 1; 1 << k <= d; k++)
        pp[i][k] = pp[pp[i][k - 1]][k - 1];
    for (int j : aa[i])
        if (j != p)
            dfs(i, j, d + 1);
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
    int n, q;
    scanf("%d%d", &n, &q);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs(-1, 0, 0);
    while (q--) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        int a = lca(i, j);
        printf("%d\n", dd[i] + dd[j] - dd[a] * 2);
    }
    return 0;
}
