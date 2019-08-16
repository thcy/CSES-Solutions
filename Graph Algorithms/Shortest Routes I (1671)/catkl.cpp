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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n+1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vector<ll> d(n+1, inf);
    typedef pair<ll, int> T;
    priority_queue<T, vector<T>, greater<T>> q;
    for(q.push({0, 1}); !q.empty(); q.pop()) {
        ll cur=q.top().first;
        int i=q.top().second;
        if (d[i]<inf) continue;
        d[i]=cur;
        trav(p, g[i]) q.push({cur+p.second, p.first});
    }
    rep(i, 1, n+1) cout << d[i] << " \n"[i==n];
    return 0;
}
