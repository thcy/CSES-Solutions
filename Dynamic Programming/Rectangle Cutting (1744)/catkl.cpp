#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int N=512;
    constexpr int inf=1e9;
    vector<vi> dp(N, vi(N));
    rep(i, 1, N) rep(j, 1, N) {
        dp[i][j]=(i==j? 0:inf);
        rep(k, 1, i)
        dp[i][j]=min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
        rep(k, 1, j)
        dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << '\n';
    return 0;
}
