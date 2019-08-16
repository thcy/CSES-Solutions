// https://cses.fi/problemset/task/1130
// Tree Matching
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 500000;

vector<int> aa[N];

int dp[N], dp1[N];

void dfs(int p, int i) {
    int x0 = 0, x1 = 1;
    auto &adj = aa[i];
    for (int j : adj)
        if (j != p) {
            dfs(i, j);
            x0 += dp1[j];
            x1 += dp[j];
        }
    dp1[i] = x1;
    dp[i] = min(x0, x1);
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
    dfs(-1, 0);
    printf("%d\n", dp[0]);
}
