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

int gr[7][7];
int ans = 0;
int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};
ll mask = 0;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y], par[y] = x;
        return 1;
    }
};

int countAdj(int a, int b) {
    int cnt = 0;
    F0R(i,4) {
        int A = a+xd[i], B = b+yd[i];
        if (0 <= A && A < 7 && 0 <= B && B < 7 && !gr[A][B]) cnt ++;
    }
    return cnt;
}

bool bad(ll MASK) {
    DSU<49> D = DSU<49>();
    int r = MASK>>49; int c = r%7; r /= 7;
    F0R(i,7) F0R(j,7) if (!gr[i][j] && i+j > 0 && abs(i-r)+abs(j-c) > 1 && countAdj(i,j) <= 1){
        /*F0R(i,7) {
         F0R(j,7) cout << gr[i][j];
         cout << "\n";
         }
         ps(r,c);
         exit(0);*/
        return 1;
    }
    F0R(i,7) F0R(j,6) if (!gr[i][j] && !gr[i][j+1]) D.unite(7*i+j,7*i+j+1);
    F0R(i,6) F0R(j,7) if (!gr[i][j] && !gr[i+1][j]) D.unite(7*i+j,7*(i+1)+j);
    /*F0R(i,7) {
     F0R(j,7) ps(i,j,D.get(7*i+j));
     }*/
    F0R(i,7) F0R(j,7) if (!gr[i][j] && D.get(7*i+j) != D.get(0)) return 1;
    return 0;
}

int st = 0;
unordered_map<ll,int> WAYS;
unordered_map<ll,bool> BAD;

/*st ++;
 if (st == 3000000) {
 F0R(i,7) {
 F0R(j,7) cout << gr[i][j];
 cout << "\n";
 }
 exit(0);
 }*/

string s;

bool match(int ind, int dir) {
    if (s[ind] == '?') return 1;
    if (s[ind] == 'U') return dir == 0;
    if (s[ind] == 'L') return dir == 3;
    if (s[ind] == 'D') return dir == 2;
    if (s[ind] == 'R') return dir == 1;
    exit(5);
}

int dfs(int ind, int r, int c) {
    if (r < 0 || r >= 7 || c < 0 || c >= 7 || gr[r][c]) return 0;
    if (ind == 48) {
        /*F0Rd(j,7) {
         F0R(i,7) pr(gr[i][j],'\t');
         ps();
         }
         exit(0);*/
        return mp(r,c) == mp(0,0);
    }
    gr[r][c] = ind+1; mask ^= 1LL<<(7*r+c);
    ll MASK = mask^((ll)(7*r+c)<<49);
    if (!WAYS.count(MASK)) {
        int ret = 0;
        if (!BAD.count(MASK)) BAD[MASK] = bad(MASK);
        if (!BAD[MASK]) F0R(i,4) if (match(ind,i)) {
            int z = dfs(ind+1,r+xd[i],c+yd[i]);
            // if (ind+1 == 48) ps("HA",z,r,c,i,r+xd[i],c+yd[i]);
            ret += z;
        }
        WAYS[MASK] = ret;
    }
    gr[r][c] = 0; mask ^= 1LL<<(7*r+c);
    return WAYS[MASK];
}

int main() {
    // ps(bad()); exit(0);
    setIO(); re(s);
    // ps(s);
    // ps(st);
    // ps(ans);
    ps(dfs(0,0,6));
    // ps(mask);
    // ps(sz(BAD),sz(WAYS));
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?), set tle
 * do smth instead of nothing and stay organized
 */
