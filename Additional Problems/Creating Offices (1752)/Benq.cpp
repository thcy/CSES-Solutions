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

int n,d;
vi adj[MX], dp[MX], stor[MX];

vi ins(vi a) {
    a.pb(a.back());
    return a;
}

void comb(int A, vi b) {
    vi& a = dp[A]; assert(sz(a) >= sz(b));
    // >= d/2:
    int lo = (d+1)/2;
    FOR(i,max(d-sz(b)+1,0),min(lo,sz(a))) {
        assert(i < sz(a) && d-i < sz(b));
        a[sz(a)-1-i] += b[sz(b)-1-(d-i)];
    }
    FOR(i,max(d-sz(a)+1,0),min(lo,sz(b))) b[sz(b)-1-i] += a[sz(a)-1-(d-i)]; // 0 <= d-i < sz(a)
    FOR(i,lo,sz(b)) a[sz(a)-1-i] += b[sz(b)-1-i];
    F0Rd(i,sz(b)) {
        ckmax(a[sz(a)-1-i],b[sz(b)-1-i]);
        if (i+1 < sz(a)) ckmax(a[sz(a)-1-i],a[sz(a)-1-(i+1)]);
    }
    // < d/2
}

void dfs(int a, int b) {
    if (b) adj[a].erase(find(all(adj[a]),b));
    trav(t,adj[a]) dfs(t,a);
    FOR(i,1,sz(adj[a])) if (sz(dp[adj[a][i]]) > sz(dp[adj[a][0]])) swap(adj[a][0],adj[a][i]);
    if (sz(adj[a])) {
        swap(dp[a],dp[adj[a][0]]); dp[a].pb(dp[a].back());
        comb(a,{1});
        FOR(i,1,sz(adj[a])) {
            int z = sz(dp[adj[a][i]]);
            stor[adj[a][i]] = vi(dp[a].end()-z-1,dp[a].end());
            comb(a,ins(dp[adj[a][i]]));
        }
    } else dp[a] = {1};
    //ps("??",a,dp[a]);
    // ps(a,b,adj[a],dp[a]);
}

void dfs2(int a, int ind);

void solve(int A, int B, int& ind) {
    if (ind < 0) return;
    int val = dp[A][ind];
    F0R(i,sz(stor[B])) swap(dp[A][sz(dp[A])-1-i],stor[B][sz(stor[B])-1-i]);
    const vi& a = dp[A]; const vi b = ins(dp[B]);
    
    if (a[ind] == val) return;
    if (b[sz(b)-(sz(a)-ind)] == val) {
        ind = -1; dfs2(B,sz(b)-(sz(a)-ind));
        return;
    }
    int lo = (d+1)/2; int zz = sz(b)-(sz(a)-ind);
    if (sz(a)-1-ind >= lo && a[ind]+(zz >= 0 ? b[zz] : 0) >= val) {
        assert(a[ind]+(zz >= 0 ? b[zz] : 0) == val);
        dfs2(B,zz); return;
    }
    
    // ps("WUT",A,B,ind,sz(a)-1-ind,val); exit(0);
    FOR(i,max(d-sz(b)+1,0),min(lo,sz(a))) {
        if (sz(a)-1-i <= ind && a[sz(a)-1-i]+b[sz(b)-1-(d-i)] >= val) {
            ind = sz(a)-1-i; dfs2(B,sz(b)-1-(d-i));
            return;
        }
    }
    FOR(i,max(d-sz(a)+1,0),min(lo,sz(b))) {
        if (sz(b)-1-i <= ind && b[sz(b)-1-i]+a[sz(a)-1-(d-i)] >= val) {
            ind = sz(a)-1-(d-i); dfs2(B,sz(b)-1-i);
            return;
        }
    }
    ps("OOPS",ind,val,A,B,a,b);
    exit(0);
    exit(5);
}

void dumb(int a, int ind) {
    ckmin(ind,sz(dp[a])-1);
    if (ind < 0) return;
    if (ind == sz(dp[a])-1) {
        if (ind < d || dp[a][ind-d]+1 != dp[a][ind]) {
            ps("??",ind,d,dp[a],dp[a][ind-1],dp[a][ind]);
            exit(0);
        }
        ps(a); ind -= d;
    }
    dp[a].pop_back(); swap(dp[adj[a][0]],dp[a]);
    dfs2(adj[a][0],ind);
}

void dfs2(int a, int ind) {
    ckmin(ind,sz(dp[a])-1);
    if (ind < 0) return;
    if (sz(adj[a]) == 0) { ps(a); return; }
    // ps("HA",a,ind,dp[a]);
    FORd(i,1,sz(adj[a])) {
        while (ind > 0 && dp[a][ind-1] == dp[a][ind]) ind --;
        solve(a,adj[a][i],ind);
    }
    while (ind > 0 && dp[a][ind-1] == dp[a][ind]) ind --;
    dumb(a,ind);
    // swap(dp[a],dp[adj[a][0]]); dp[a].pb(dp[a].back()); comb(dp[a],{1});
}

int main() {
    setIO(); re(n,d);
    F0R(i,n-1) {
        int a,b; re(a,b);
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    ps(dp[1].back());
    dfs2(1,sz(dp[1])-1);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?), set tle
 * do smth instead of nothing and stay organized
 */
