#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

vector<vi> graph;

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

template <int V> struct HeavyLight { // sum queries, sum updates
    int parent[V], heavy[V], depth[V];
    int root[V], treePos[V];
    BIT<ll,V> tree;
    
    void init() {
        int n = graph.size();
        FOR(i,1,n+1) heavy[i] = -1;
        parent[1] = -1, depth[1] = 0;
        dfs(1);
        for (int i = 1, currentPos = 0; i <= n; ++i)
            if (parent[i] == -1 || heavy[parent[i]] != i)
                for (int j = i; j != -1; j = heavy[j]) {
                    root[j] = i;
                    treePos[j] = ++currentPos;
                }
    }
    
    int dfs(int v) {
        int size = 1, maxSubtree = 0;
        for (auto u : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(u);
            if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
            size += subtree;
        }
        return size;
    }
    
    template <class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op) {
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(treePos[root[v]], treePos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(treePos[u], treePos[v]); // assumes values are stored in edges, not vertices
    }
    
    void modifyPath(int u, int value) {
        u = treePos[u];
        tree.upd(u,value-tree.query(u,u));
    }
    
    ll queryPath(int u, int v) {
        ll res = 0;
        processPath(u, v, [this, &res](int l, int r) { res += tree.query(l, r); });
        return res;
    }
};

HeavyLight<1<<18> H;
int N,Q, v[1<<18];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    FOR(i,1,N+1) cin >> v[i];
    graph.resize(N+1);
    F0R(i,N-1) {
        int a,b; cin >> a >> b;
        graph[a].pb(b), graph[b].pb(a);
    }
    H.init();
    FOR(i,1,N+1) H.modifyPath(i,v[i]);
    F0R(i,Q) {
        int t; cin >> t;
        if (t == 1) {
            int s,x; cin >> s >> x;
            H.modifyPath(s,x);
        } else {
            int s; cin >> s;
            cout << H.queryPath(1,s) << "\n";
        }
    }
}
