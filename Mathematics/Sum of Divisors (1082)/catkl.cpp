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
    constexpr int P2=(P+1)/2;
    ll n, ans=0;
    cin >> n;
    for(ll i=1; i<=n/i; i++)
        ans=(ans+(n/i)*i)%P;
    for(ll j=1; j<n/j; j++) {
        ll L=max(j+1, n/(j+1)+1);
        ll R=n/j+1;
        ans=(ans+(R-L)%P*((R+L-1)%P)%P*P2%P*j)%P;
    }
    cout << ans << '\n';
    return 0;
}
