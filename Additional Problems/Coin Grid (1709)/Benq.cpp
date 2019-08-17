/*
 ID: bqi3431
 PROG: ~
 LANG: C++11
 */

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }
    
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
    
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }
    
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a);
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val;
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); }
    // inv is equivalent to return exp(b,b.mod-2) if prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template<int SZ> struct Dinic {
    struct Edge { int v, rev; ll flow, cap; };
    
    vector<Edge> adj[SZ];
    
    void addEdge(int u, int v, ll cap) {
        Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
        adj[u].pb(a), adj[v].pb(b);
    }
    
    int ST, EN, level[SZ], ind[SZ];
    
    bool bfs() { // level = shortest distance from source
        // after computing flow, edges {u,v} such that level[u] \neq -1, level[v] = -1 are part of min cut
        F0R(i,SZ) level[i] = -1, ind[i] = 0;
        level[ST] = 0;
        
        queue<int> q; q.push(ST);
        while (sz(q)) {
            int u = q.front(); q.pop();
            trav(e,adj[u]) if (level[e.v] < 0 && e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
        
        return level[EN] >= 0;
    }
    
    ll sendFlow(int s, ll flow) {
        if (s == EN) return flow;
        
        for (  ; ind[s] < sz(adj[s]); ind[s] ++) {
            Edge& e = adj[s][ind[s]];
            
            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll f = sendFlow(e.v, min(flow, e.cap - e.flow));
            
            if (f) { // saturate at least one edge
                e.flow += f; adj[e.v][e.rev].flow -= f;
                return f;
            }
        }
        
        return 0;
    }
    
    ll maxFlow(int _ST, int _EN) {
        ST = _ST, EN = _EN;
        if (ST == EN) return -1;
        ll tot = 0;
        while (bfs()) while (auto flow = sendFlow(ST, LLONG_MAX)) tot += flow;
        return tot;
    }
};

Dinic<202> D;
int n;

int main() {
    setIO();  re(n);
    F0R(i,n) {
        D.addEdge(0,i+1,1);
        D.addEdge(i+1+n,2*n+1,1);
        F0R(j,n) {
            char c; re(c);
            if (c == 'o') {
                D.addEdge(i+1,j+1+n,MOD);
            }
        }
    }
    ps(D.maxFlow(0,2*n+1));
    D.bfs();
    trav(t,D.adj[0]) if (D.level[t.v] < 0) ps(1,t.v);
    FOR(i,n+1,2*n+1) trav(t,D.adj[i]) if (t.v == 2*n+1 && D.level[i] >= 0) ps(2,i-n);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?), set tle
 * do smth instead of nothing and stay organized
 */
