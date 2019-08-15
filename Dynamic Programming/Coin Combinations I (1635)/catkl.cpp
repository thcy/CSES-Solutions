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
    
    constexpr int P=1e9+7;
    int n, x;
    cin >> n >> x;
    vi c(n), dp(x+1);
    dp[0]=1;
    rep(i, 0, n) cin >> c[i];
    auto add=[&](int &x, int a) {
        x+=a;
        if (x>=P) x-=P;
    };
    rep(i, 0, x+1) trav(a, c)
    if (i>=a) add(dp[i], dp[i-a]);
    cout << dp[x] << '\n';
    return 0;
}
