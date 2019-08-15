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
    
    constexpr ll inf=1e18;
    int n;
    cin >> n;
    vi p(n);
    ll s=0;
    rep(i, 0, n) {
        cin >> p[i];
        s+=p[i];
    }
    int M=1<<n;
    ll opt=inf;
    rep(m, 0, M) {
        ll t=0;
        rep(j, 0, n)
        if (m&(1<<j)) t+=p[j];
        opt=min(opt, abs(2*t-s));
    }
    cout << opt <<'\n';
    return 0;
}
