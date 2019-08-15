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
    
    int n, x;
    cin >> n >> x;
    vi h(n), s(n), dp(x+1);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) for(int j=x; j>=h[i]; j--)
        dp[j]=max(dp[j], dp[j-h[i]]+s[i]);
    cout << dp[x] << '\n';
    return 0;
}
