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
struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) (s[pos] += dif)%=P;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res%P;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >>  n;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    vi y(x);
    sort(all(y));
    y.erase(unique(all(y)), end(y));
    trav(a, x) a=lower_bound(all(y), a)-begin(y);
    FT t(n);
    ll ans=0;
    rep(i, 0, n) {
        ll cur=t.query(x[i])+1;
        (ans+=cur)%=P;
        t.update(x[i], cur);
    }
    cout << ans << '\n';
    return 0;
}
