#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<pii> vpi;
typedef vector<vpi> graph;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    
    RMQ(const vector<T>& V) {
        int N = sz(V), on = 1, depth = 1;
        while (on < N) on *= 2, depth++;
        jmp.assign(depth, V);
        rep(i,0,depth-1) rep(j,0,N)
        jmp[i+1][j] = min(jmp[i][j],
                          jmp[i][min(N - 1, j + (1 << i))]);
    }
    
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    vi time;
    vector<ll> dist;
    RMQ<pii> rmq;
    
    LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}
    
    vpi dfs(graph& C) {
        vector<tuple<int, int, int, ll>> q(1);
        vpi ret;
        int T = 0, v, p, d; ll di;
        while (!q.empty()) {
            tie(v, p, d, di) = q.back();
            q.pop_back();
            if (d) ret.emplace_back(d, p);
            time[v] = T++;
            dist[v] = di;
            trav(e, C[v]) if (e.first != p)
                q.emplace_back(e.first, v, d+1, di + e.second);
        }
        return ret;
    }
    
    int query(int a, int b) {
        if (a == b) return a;
        a = time[a], b = time[b];
        return rmq.query(min(a, b), max(a, b)).second;
    }
    ll distance(int a, int b) {
        int lca = query(a, b);
        return dist[a] + dist[b] - 2 * dist[lca];
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    graph g(n);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }
    LCA x(g);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << x.distance(a, b) << '\n';
    }
    return 0;
}
