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
    vi x(n+2);
    rep(i, 1, n+1) cin >> x[i];
    vi L(n+2), R(n+2);
    vi s(1);
    rep(i, 1, n+1) {
        while (x[i]<=x[s.back()])
            s.pop_back();
        L[i]=s.back();
        s.push_back(i);
    }
    s.assign(1, n+1);
    for(int i=n; i>0; i--) {
        while (x[i]<=x[s.back()])
            s.pop_back();
        R[i]=s.back();
        s.push_back(i);
    }
    ll ans=0;
    rep(i, 1, n+1)
    ans=max(ans, 1LL*x[i]*(R[i]-L[i]-1));
    cout << ans << '\n';
    return 0;
}
