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

vector<unordered_map<int, int>> g, gc;
vi s;

void dfs(int i) {
    s.push_back(i);
    if (i==1) return;
    trav(p, g[i]) if (p.second>gc[i][p.first]) {
        p.second--;
        dfs(p.first);
        return;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >>b;
        g[a][b]++;
    }
    gc=g;
    int flow=edmondsKarp(g, 1, n);
    cout << flow << '\n';
    rep(f, 0, flow) {
        s.clear();
        dfs(n);
        int l=sz(s);
        cout << l << '\n';
        rep(i, 0, l) cout << s[l-1-i] << " \n"[i==l-1];
    }
    return 0;
}
