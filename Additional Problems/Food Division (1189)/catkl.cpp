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
    vector<ll> a(n), b(n),  s(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 1, n) s[i]=a[i]-b[i]+s[i-1];
    sort(all(s));
    ll ans=0;
    rep(i, 0, n) ans+=abs(s[i]-s[n/2]);
    cout << ans << '\n';
    return 0;
}
