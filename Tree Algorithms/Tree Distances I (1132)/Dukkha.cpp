// https://cses.fi/problemset/task/1132
// Tree Distances
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 500000;

struct V {
    vector<int> adj;
    int d1, d2;
} vv[N];

void dfs1(int p, int i) {
    V &u = vv[i];
    int d1 = -1, d2 = -1;
    for (int j : u.adj)
        if (j != p) {
            dfs1(i, j);
            int d = vv[j].d1;
            if (d1 < d) {
                d2 = d1; d1 = d;
            } else if (d2 < d)
                d2 = d;
        }
    u.d1 = d1 + 1;
    u.d2 = d2 + 1;
}

void dfs2(int p, int i, int d_) {
    V &u = vv[i];
    int d1_ = max(d_, u.d1);
    int d2_ = max(d_, u.d2);
    for (int j : u.adj)
        if (j != p) {
            V &v = vv[j];
            dfs2(i, j, (v.d1 + 1 == u.d1 ? d2_ : d1_) + 1);
        }
    u.d1 = d1_;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j); i--, j--;
        vv[i].adj.push_back(j);
        vv[j].adj.push_back(i);
    }
    dfs1(-1, 0);
    dfs2(-1, 0, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", vv[i].d1);
    printf("\n");
}
