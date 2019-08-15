#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int P=1e9+7;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n)
    cin >> s[i];
    vector<vi> dp(n, vi(n));
    dp[0][0]=(s[0][0]=='.');
    rep(i, 0, n) rep(j, 0, n) {
        if (s[i][j]=='*') continue;
        if (i) dp[i][j]+=dp[i-1][j];
        if (dp[i][j]>=P) dp[i][j]-=P;
        if (j) dp[i][j]+=dp[i][j-1];
        if (dp[i][j]>=P) dp[i][j]-=P;
    }
    cout << dp[n-1][n-1] << '\n';
    return 0;
}
