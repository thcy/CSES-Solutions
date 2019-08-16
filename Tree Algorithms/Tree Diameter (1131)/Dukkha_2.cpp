// https://cses.fi/problemset/task/1131
// Tree Diameter
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 500000;

vector<int> aa[N];

int d_, i_;

void dfs(int p, int i, int d) {
    if (d_ < d) {
        d_ = d;
        i_ = i;
    }
    auto &adj = aa[i];
    for (int j : adj)
        if (j != p)
            dfs(i, j, d + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs(-1, 0, 0);
    dfs(-1, i_, 0);
    printf("%d\n", d_);
}
