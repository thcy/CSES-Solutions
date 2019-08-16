#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct V {
    vector<pii> outs; // (dest, edge index)
    int nins = 0;
};

vi euler_walk(vector<V>& nodes, int nedges, int src=0) {
    int c = 0;
    trav(n, nodes) c += abs(n.nins - sz(n.outs));
    if (c > 2) return {};
    vector<vector<pii>::iterator> its;
    trav(n, nodes)
    its.push_back(n.outs.begin());
    vector<bool> eu(nedges);
    vi ret, s = {src};
    while(!s.empty()) {
        int x = s.back();
        auto& it = its[x], end = nodes[x].outs.end();
        while(it != end && eu[it->second]) ++it;
        if(it == end) { ret.push_back(x); s.pop_back(); }
        else { s.push_back(it->first); eu[it->second] = true; }
    }
    if(sz(ret) != nedges+1)
        ret.clear(); // No Eulerian cycles/paths.
    // else, non-cycle if ret.front() != ret.back()
    reverse(all(ret));
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<V> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].outs.push_back({b, i});
        g[b].outs.push_back({a, i});
        g[a].nins++, g[b].nins++;
    }
    int odd=0;
    rep(i, 0, n) odd+=(g[i].nins%2);
    vi ans=euler_walk(g, m, 0);
    if (odd || sz(ans)!=m+1 || ans.back()!=0)
        cout << "IMPOSSIBLE\n";
    else
        rep(i, 0, m+1) cout << ans[i]+1 << " \n"[i==m];
    return 0;
}
