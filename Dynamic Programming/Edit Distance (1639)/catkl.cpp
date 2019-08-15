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
    
    string s, t;
    cin >> s >> t;
    int n=sz(s), m=sz(t);
    vector<vi> dp(n+1, vi(m+1));
    rep(i, 0, m+1) dp[0][i]=i;
    rep(i, 1, n+1) {
        dp[i][0]=i;
        rep(j, 1, m+1) {
            dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
            dp[i][j]=min(dp[i][j], dp[i-1][j-1]+(s[i-1]!=t[j-1]));
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
