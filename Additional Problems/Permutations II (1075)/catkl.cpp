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
    
    constexpr ll P=1e9+7;
    ll n;
    cin >> n;
    vector<vector<ll>> B(n+1, vector<ll>(n+1));
    rep(i, 0, n+1) {
        B[i][0]=1;
        rep(j, 1, i+1) {
            B[i][j]=B[i-1][j]+B[i-1][j-1];
            if (B[i][j]>=P) B[i][j]-=P;
        }
    }
    vector<ll> f(n+1);
    f[0]=1;
    rep(i, 1, n+1) f[i]=f[i-1]*i%P;
    ll ans=0;
    rep(k, 0, n) {
        ll s=0;
        rep(a, 0, k+1) s=(s+B[n-k][a]*B[n-a-1][k-a])%P;
        s=s*f[n-k]%P;
        ans=(ans+(k%2? P-s : s))%P;
    }
    cout << ans << '\n';
    return 0;
}
