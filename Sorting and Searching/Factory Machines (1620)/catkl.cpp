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
    
    ll n, t;
    cin >> n >> t;
    vector<ll> k(n);
    rep(i, 0, n) cin >> k[i];
    ll L=1, R=k[0]*t;
    while (L<R) {
        ll M=(L+R)/2;
        ll s=0;
        rep(i, 0, n) s+=M/k[i];
        if (s<t) L=M+1;
        else R=M;
    }
    cout << L << '\n';
    return 0;
}
