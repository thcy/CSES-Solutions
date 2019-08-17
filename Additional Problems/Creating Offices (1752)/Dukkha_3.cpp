// https://cses.fi/problemset/task/1752
// Creating Offices
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, N = 200000;

vector<int> aa[N];
bool used[N];
int cc[N], dd[N], dd_[N], lambda;

void dfs(int p, int i, int d) {
    dd[i] = d;
    int d_ = INF, c_ = -1;
    for (int j : aa[i])
        if (j != p) {
            dfs(i, j, d + 1);
            d_ = min(d_, dd_[j]);
            int c = cc[j];
            if (c == -1)
                continue;
            if ((dd[c] - d) * 2 >= lambda) {
                used[c] = true;
                d_ = min(d_, dd[c]);
            } else if (c_ == -1 || dd[c_] < dd[c])
                c_ = c;
        }
    dd_[i] = d_;
    if (c_ != -1 && dd[c_] - d + d_ - d < lambda)
        c_ = -1;
    if (c_ == -1 && d_ - d >= lambda)
        c_ = i;
    cc[i] = c_;
}

int main() {
    int n;
    scanf("%d%d", &n, &lambda);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j), i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs(-1, 0, 0);
    if (cc[0] != -1)
        used[cc[0]] = true;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (used[i])
            k++;
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
        if (used[i])
            printf("%d ", i + 1);
    printf("\n");
    return 0;
}
