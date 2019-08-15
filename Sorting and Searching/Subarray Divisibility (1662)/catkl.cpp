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
    vi h(n);
    ll s=0, ans=0;
    rep(i, 0, n) {
        h[s]++;
        ll a;
        cin >> a;
        s=(s+n+a%n)%n;
        ans+=h[s];
    }
    cout << ans << '\n';
    return 0;
}
