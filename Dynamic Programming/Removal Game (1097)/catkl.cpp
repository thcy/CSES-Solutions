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
    
    int n;
    cin >> n;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    rep(l, 1, n+1) rep(i, 0, n+1-l)
    dp[l][i]=max(x[i]-dp[l-1][i+1], x[i+l-1]-dp[l-1][i]);
    cout << (dp[n][0]+accumulate(all(x), 0LL))/2 << '\n';
    return 0;
}
