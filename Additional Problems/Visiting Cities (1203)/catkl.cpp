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

void dijkstra(int s, vector<vector<pii>> &g, vector<ll> &d) {
    typedef pair<ll, ll> T;
    priority_queue<T, vector<T>, greater<T>> q;
    for (q.push({0, s}); !q.empty(); q.pop()) {
        ll cur=q.top().first;
        int i=q.top().second;
        if (d[i]<inf) continue;
        d[i]=cur;
        trav(p, g[i])
        q.push({cur+p.second, p.first});
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
    dijkstra(1, g1, d1);
    dijkstra(n, g2, d2);
    vi o;
    rep(i, 1, n+1) if (d1[i]+d2[i]==d1[n])
        o.push_back(i);
    sort(all(o), [&](int i, int j) {
        return d1[i]<d1[j];
    });
    int np=sz(o);
    vi id(n+1, -1);
    rep(i, 0, np) id[o[i]]=i;
    vi ans;
    int k=0;
    rep(i, 0, np) {
        if (k==i) ans.push_back(o[i]);
        trav(p, g1[o[i]])
        if (d1[o[i]]+p.second+d2[p.first]==d1[n])
            k=max(k, id[p.first]);
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    rep(i, 0, sz(ans))
    cout << ans[i] << " \n"[i==sz(ans)-1];
    return 0;
}
