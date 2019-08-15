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
    
    constexpr int inf=2e9;
    int n;
    cin >> n;
    vector<array<int, 3>> x(n);
    rep(i, 0, n) rep(j, 0, 3) cin >> x[i][j];
    sort(all(x));
    reverse(all(x));
    map<int, ll> dp;
    dp.insert({inf, 0});
    trav(p, x) {
        ll val=begin(dp)->second;
        dp[p[0]]=val;
        val=dp.upper_bound(p[1])->second;
        dp[p[0]]=max(dp[p[0]], val+p[2]);
    }
    cout << begin(dp)->second;
    return 0;
}
