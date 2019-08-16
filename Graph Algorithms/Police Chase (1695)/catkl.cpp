#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T> T edmondsKarp(vector<unordered_map<int, T>>& graph, int source, int sink) {
    assert(source != sink);
    T flow = 0;
    vi par(sz(graph)), q = par;
    
    for (;;) {
        fill(all(par), -1);
        par[source] = 0;
        int ptr = 1;
        q[0] = source;
        
        rep(i,0,ptr) {
            int x = q[i];
            trav(e, graph[x]) {
                if (par[e.first] == -1 && e.second > 0) {
                    par[e.first] = x;
                    q[ptr++] = e.first;
                    if (e.first == sink) goto out;
                }
            }
        }
        return flow;
    out:
        T inc = numeric_limits<T>::max();
        for (int y = sink; y != source; y = par[y])
            inc = min(inc, graph[par[y]][y]);
        
        flow += inc;
        for (int y = sink; y != source; y = par[y]) {
            int p = par[y];
            if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
            graph[y][p] += inc;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> g(n+1), gc;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g[a][b]++, g[b][a]++;
    }
    gc=g;
    cout << edmondsKarp<int>(g, 1, n) << '\n';
    vi v(n+1);
    function<void(int)> dfs=[&](int i) {
        v[i]=1;
        trav(p, g[i]) if (!v[p.first]) dfs(p.first);
    };
    dfs(1);
    rep(i, 1, n+1) trav(p, gc[i])
    if(v[i] && !v[p.first])
        cout << i << " " << p.first << '\n';
    return 0;
}
