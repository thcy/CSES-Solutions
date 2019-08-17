#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void process(vector<ll> &H, vi x) {
    int n=sz(x);
    H.resize(1<<n);
    int k=1;
    rep(i, 0, n) rep(j, 0, 1<<i)
    H[k++]=H[j]+x[i];
    sort(all(H));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, s;
    cin >> n >> s;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    vector<ll> L, R;
    process(L, vi(begin(x), begin(x)+n/2));
    process(R, vi(begin(x)+n/2, end(x)));
    ll ans=0;
    trav(a, L) {
        auto l=lower_bound(all(R), s-a);
        auto r=upper_bound(all(R), s-a);
        ans+=r-l;
    }
    cout << ans << '\n';
    return 0;
}
