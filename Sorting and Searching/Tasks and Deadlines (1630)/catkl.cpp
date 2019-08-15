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
    vector<pii> e(n);
    rep(i, 0, n) cin >> e[i].first >> e[i].second;
    sort(all(e));
    ll s=0, ans=0;
    rep(i, 0, n) {
        s+=e[i].first;
        ans+=e[i].second-s;
    }
    cout << ans << '\n';
    return 0;
}
