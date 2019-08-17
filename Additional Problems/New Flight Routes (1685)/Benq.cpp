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

vi ADJ[MX], RADJ[MX];
bool con[MX];
int out[MX], in[MX];
set<int> OUT[MX], IN[MX];

template<int SZ> struct scc {
    int N, comp[SZ];
    vi adj[SZ], radj[SZ], todo, allComp;
    bitset<SZ> visit;
    
    void addEdge(int a, int b) { adj[a].pb(b), radj[b].pb(a); }
    
    void dfs(int v) {
        visit[v] = 1;
        trav(w,adj[v]) if (!visit[w]) dfs(w);
        todo.pb(v);
    }
    
    void dfs2(int v, int val) {
        comp[v] = val;
        trav(w,radj[v]) if (comp[w] == -1) dfs2(w,val);
    }
    
    void genSCC(int _N) { // fills allComp
        N = _N;
        FOR(i,1,N+1) comp[i] = -1, visit[i] = 0;
        FOR(i,1,N+1) if (!visit[i]) dfs(i);
        reverse(all(todo)); // toposort
        trav(i,todo) if (comp[i] == -1) dfs2(i,i), allComp.pb(i);
        FOR(i,1,N+1) con[comp[i]] = 1;
        FOR(i,1,N+1) trav(j,adj[i]) if (comp[i] != comp[j]) {
            ADJ[comp[i]].pb(comp[j]);
            RADJ[comp[j]].pb(comp[i]);
        }
    }
};

scc<MX> S;
int n,m;

void init() {
    setIO(); re(n,m);
    F0R(i,m) {
        int a,b; re(a,b);
        S.addEdge(a,b);
    }
    S.genSCC(n);
    if (sz(S.allComp) == 1) {
        ps(0);
        exit(0);
    }
}

void addEdge(int a, int b) {
    OUT[a].insert(b), IN[b].insert(a);
}

bool done[MX];

int main() {
    init();
    // ps(S.allComp);
    F0Rd(i,sz(S.allComp)) {
        int t = S.allComp[i];
        if (!sz(ADJ[t])) out[t] = t;
        else trav(u,ADJ[t]) ckmax(out[t],out[u]);
        if (!sz(RADJ[t])) addEdge(t,out[t]);
    }
    F0R(i,sz(S.allComp)) {
        int t = S.allComp[i];
        if (!sz(RADJ[t])) in[t] = t;
        else trav(u,RADJ[t]) ckmax(in[t],in[u]);
        if (!sz(ADJ[t]) && !sz(IN[t])) {
            if (sz(OUT[in[t]]) == 1) {
                int x = *OUT[in[t]].begin();
                if (sz(IN[x]) > 1) {
                    IN[x].erase(in[t]);
                    OUT[in[t]].erase(x);
                }
            }
            addEdge(in[t],t);
        }
    }
    // trav(t,S.allComp) ps(t,OUT[t],IN[t]);
    vector<pair<vi,vi>> v;
    trav(t,S.allComp) if (sz(OUT[t]) && !done[t]) {
        pair<vi,vi> p;
        if (sz(OUT[t]) > 1) {
            p.f.pb(t);
            trav(x,OUT[t]) {
                assert(sz(IN[x]) == 1);
                p.s.pb(x);
            }
        } else {
            trav(x,IN[*OUT[t].begin()]) {
                assert(sz(OUT[x]) == 1);
                done[x] = 1;
                p.f.pb(x);
            }
            p.s.pb(*OUT[t].begin());
        }
        v.pb(p);
    }
    // ps(v);
    vpi des;
    vi a,b;
    F0R(i,sz(v)) {
        int j = (i+1)%sz(v);
        des.pb({v[i].s.back(),v[j].f.back()});
        v[i].s.pop_back(); v[j].f.pop_back();
    }
    F0R(i,sz(v)) {
        a.insert(a.end(),all(v[i].f));
        b.insert(b.end(),all(v[i].s));
    }
    while (sz(a) && sz(b)) {
        des.pb({b.back(),a.back()});
        a.pop_back(), b.pop_back();
    }
    while (sz(a)) {
        des.pb({des[0].f,a.back()});
        a.pop_back();
    }
    while (sz(b)) {
        des.pb({b.back(),des[0].f});
        b.pop_back();
    }
    ps(sz(des));
    trav(t,des) ps(t.f,t.s);
    // trav(t,S.allComp) if (sz(ADJ[t]) == 0) ps(t);
    /*vi a,b;
     trav(t,S.allComp) {
     if (!S.in[t]) a.pb(t);
     if (!S.out[t]) b.pb(t);
     }
     ps(a,b);*/
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?), set tle
 * do smth instead of nothing and stay organized
 */
