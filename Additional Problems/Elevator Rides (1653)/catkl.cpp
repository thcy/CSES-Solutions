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
    
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    int M=1<<n;
    vector<ll> w(M);
    rep(m, 0, M) rep(i, 0, n)
    if (m&(1<<i)) w[m]+=a[i];
    vector<ll> dp(M);
    rep(ans, 1, n+1) {
        rep(b, 0, n) rep(m, 0, M)
        if (m&(1<<b)) dp[m]=max(dp[m], dp[m^(1<<b)]);
        rep(m, 0, M)
        dp[m]=(dp[m]>=w[m]-x? w[m]:0);
        if (dp[M-1]>0) {
            cout << ans << '\n';
            return 0;
        }
    }
    return 0;
}
