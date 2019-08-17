#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll P=1e9+7;
vector<ll> f, invf;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % P, e /= 2)
        if (e & 1) ans = ans * b % P;
    return ans;
}

ll B(int a, int b) {
    return f[a]*invf[b]%P*invf[a-b]%P;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    f.resize(2*n+1);
    invf.resize(2*n+1);
    f[0]=1;
    rep(i, 1, 2*n+1) f[i]=f[i-1]*i%P;
    invf[2*n]=modpow(f[2*n], P-2);
    for(int i=2*n; i; i--)
        invf[i-1]=invf[i]*i%P;
    vector<pii> t(m);
    rep(i, 0, m)
    cin >> t[i].first >> t[i].second;
    t.push_back({n, n});
    sort(all(t));
    vector<ll> dp(m+1);
    rep(i, 0, m+1) {
        int r=t[i].first;
        int c=t[i].second;
        dp[i]=B(r+c-2, r-1);
        rep(j, 0, i) {
            int R=t[j].first;
            int C=t[j].second;
            if (R<=r && C<=c)
                dp[i]=(dp[i]+P-B(r-R+c-C, r-R)*dp[j]%P)%P;
        }
    }
    cout << dp[m] << '\n';
    return 0;
}
