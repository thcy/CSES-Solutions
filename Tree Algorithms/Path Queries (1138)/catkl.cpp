#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

typedef vector<pii> vpi;

struct Node {
    int d, par, val, chain = -1, pos = -1;
};

struct Chain {
    int par, val;
    vector<int> nodes;
    Tree tree;
};

struct HLD {
    typedef ll T;
    const T LOW = 0;
    void f(T& a, T b) { a += b; }
    
    vector<Node> V;
    vector<Chain> C;
    
    HLD(vector<vpi>& g) : V(sz(g)) {
        dfs(0, -1, g, 0);
        trav(c, C) {
            c.tree = {sz(c.nodes), 0};
            for (int ni : c.nodes)
                c.tree.update(V[ni].pos, V[ni].val);
        }
    }
    
    void update(int node, T val) {
        Node& n = V[node]; n.val = val;
        if (n.chain != -1) C[n.chain].tree.update(n.pos, val);
    }
    
    int pard(Node& nod) {
        if (nod.par == -1) return -1;
        return V[nod.chain == -1 ? nod.par : C[nod.chain].par].d;
    }
    
    // query all *edges* between n1, n2
    pair<T, int> query(int i1, int i2) {
        T ans = LOW;
        while(i1 != i2) {
            Node n1 = V[i1], n2 = V[i2];
            if (n1.chain != -1 && n1.chain == n2.chain) {
                int lo = n1.pos, hi = n2.pos;
                if (lo > hi) swap(lo, hi);
                f(ans, C[n1.chain].tree.query(lo, hi));
                i1 = i2 = C[n1.chain].nodes[hi];
            } else {
                if (pard(n1) < pard(n2))
                    n1 = n2, swap(i1, i2);
                if (n1.chain == -1)
                    f(ans, n1.val), i1 = n1.par;
                else {
                    Chain& c = C[n1.chain];
                    f(ans, n1.pos ? c.tree.query(n1.pos, sz(c.nodes))
                      : c.tree.s[1]);
                    i1 = c.par;
                }
            }
        }
        return make_pair(ans, i1);
    }
    
    // query all *nodes* between n1, n2
    pair<T, int> query2(int i1, int i2) {
        pair<T, int> ans = query(i1, i2);
        f(ans.first, V[ans.second].val);
        return ans;
    }
    
    pii dfs(int at, int par, vector<vpi>& g, int d) {
        V[at].d = d; V[at].par = par;
        int sum = 1, ch, nod, sz;
        tuple<int,int,int> mx(-1,-1,-1);
        trav(e, g[at]){
            if (e.first == par) continue;
            tie(sz, ch) = dfs(e.first, at, g, d+1);
            V[e.first].val = e.second;
            sum += sz;
            mx = max(mx, make_tuple(sz, e.first, ch));
        }
        tie(sz, nod, ch) = mx;
        if (2*sz < sum) return pii(sum, -1);
        if (ch == -1) { ch = sz(C); C.emplace_back(); }
        V[nod].pos = sz(C[ch].nodes);
        V[nod].chain = ch;
        C[ch].par = at;
        C[ch].nodes.push_back(nod);
        return pii(sum, ch);
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    vector<vpi> g(n);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back({b, 0});
        g[b].push_back({a, 0});
    }
    HLD hld(g);
    rep(i, 0, n) hld.update(i, v[i]);
    while (q--) {
        int type, a, b;
        cin >> type >> a;
        a--;
        if (type==1) {
            cin >> b;
            hld.update(a, v[a]=b);
        }
        else cout << hld.query2(a, 0).first << '\n';
    }
    return 0;
}
