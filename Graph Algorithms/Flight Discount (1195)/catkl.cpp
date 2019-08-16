#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll inf=1e18;
void dijkstra(vector<vector<pii>> g, int s, vector<ll> &d) {
    typedef pair<ll, int> T;
    priority_queue<T, vector<T>, greater<T>> q;
    for(q.push({0, s}); !q.empty(); q.pop()) {
        ll curd=q.top().first;
        int i=q.top().second;
        if (d[i]!=inf) continue;
        d[i]=curd;
        trav(p, g[i]) q.push({curd+p.second, p.first});
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g1(n+1), g2(n+1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g1[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    vector<ll> d1(n+1, inf), d2(n+1, inf);
    dijkstra(g1, 1, d1);
    dijkstra(g2, n, d2);
    ll ans=inf;
    rep(i, 1, n+1) trav(p, g1[i])
    ans=min(ans, d1[i]+p.second/2+d2[p.first]);
    cout << ans << '\n';
    return 0;
}
