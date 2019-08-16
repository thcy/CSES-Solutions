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
    
    int n, q;
    cin >> n >> q;
    vector<ll> x(n+1);
    rep(i, 1, n+1) {
        cin >> x[i];
        x[i]+=x[i-1];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << x[b]-x[a-1] << '\n';
    }
    return 0;
}
