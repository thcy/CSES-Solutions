#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
    int n = sz(m);
    rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
    rep(k,0,n) rep(i,0,n) rep(j,0,n)
    if (m[i][k] != inf && m[k][j] != inf) {
        auto newDist = max(m[i][k] + m[k][j], -inf);
        m[i][j] = min(m[i][j], newDist);
    }
    rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
        if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> g(n+1, vector<ll>(n+1, inf));
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b]=g[b][a]=min(g[a][b], c);
    }
    floydWarshall(g);
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << (g[a][b]==inf? -1:g[a][b]) << '\n';
    }
    return 0;
}
