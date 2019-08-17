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
const int MX = 100005;
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

template <class T, int ...Ns> struct BIT {
    T val = 0;
    void upd(T v) { val += v; }
    T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N + 1];
    template<typename... Args> void upd(int pos, Args... args) {
        for (; pos <= N; pos += (pos&-pos)) bit[pos].upd(args...);
    }
    template<typename... Args> T sum(int r, Args... args) {
        T res = 0; for (; r; r -= (r&-r)) res += bit[r].query(args...);
        return res;
    }
    template<typename... Args> T query(int l, int r, Args... args) {
        return sum(r,args...)-sum(l-1,args...);
    }
}; // BIT<int,10,10> gives a 2D BIT

int n;
BIT<int,MX> B;

ll ry[MX], rx[MX];
vl dist;
vpl v;
string c;

vector<pair<int,pi>> hori, vert;

bool ok(int mid) {
    hori.clear(), vert.clear();
    F0R(i,mid+1) {
        pl a = v[i], b = v[i+1];
        if (a.s == b.s) {
            if (a.f < b.f) hori.pb({a.s,{i==0?a.f:a.f+1,b.f}});
            else hori.pb({a.s,{b.f,i==0?a.f:a.f-1}});
        } else {
            if (a.s < b.s) vert.pb({a.f,{i==0?a.s:a.s+1,b.s}});
            else vert.pb({a.f,{b.s,i==0?a.s:a.s-1}});
        }
    }
    sort(all(vert)), sort(all(hori));
    for (int i = 0; i < sz(vert); ) {
        int mx = -MOD;
        int I = i;
        while (i < sz(vert) && vert[i].f == vert[I].f) {
            if (vert[i].s.f <= mx) return 0;
            mx = vert[i++].s.s;
        }
    }
    for (int i = 0; i < sz(hori); ) {
        int mx = -MOD;
        int I = i;
        while (i < sz(hori) && hori[i].f == hori[I].f) {
            if (hori[i].s.f <= mx) return 0;
            mx = hori[i++].s.s;
        }
    }
    
    vector<array<int,3>> mod;
    trav(t,vert) {
        mod.pb({t.s.f,t.f,1});
        mod.pb({t.s.s+1,t.f,-1});
    }
    sort(all(mod));
    B = BIT<int,MX>();
    int ind = 0;
    trav(t,hori) {
        while (ind < sz(mod) && mod[ind][0] <= t.f) {
            B.upd(mod[ind][1],mod[ind][2]);
            ind ++;
        }
        if (B.query(t.s.f,t.s.s)) return 0;
    }
    return 1;
}

void init() {
    setIO(); re(n);
    v.pb({0,0});
    F0R(i,n) {
        char d; int x; re(d,x);
        c += d;
        v.pb(v.back());
        if (d == 'U') v.back().s += x;
        if (d == 'D') v.back().s -= x;
        if (d == 'L') v.back().f -= x;
        if (d == 'R') v.back().f += x;
        dist.pb(x);
    }
    map<ll,int> x, y;
    trav(t,v) x[t.f] = y[t.s] = 0;
    int co = 0;
    trav(t,x) {
        t.s = ++co;
        rx[co] = t.f;
    }
    co = 0;
    trav(t,y) {
        t.s = ++co;
        ry[co] = t.f;
    }
    trav(t,v) {
        t.f = x[t.f], t.s = y[t.s];
    }
}

pair<pi,pi> seg(int i) {
    pl a = v[i], b = v[i+1]; if (i == 0) return {a,b};
    if (a.s == b.s) {
        if (a.f < b.f) a.f ++;
        else a.f --;
    } else {
        if (a.s < b.s) a.s ++;
        else a.s --;
    }
    return {a,b};
}

vpi inter(pair<pi,pi> a, pair<pi,pi> b) {
    if (a.f > a.s) swap(a.f,a.s);
    if (b.f > b.s) swap(b.f,b.s);
    if (a > b) swap(a,b);
    if (a.f.s == a.s.s && b.f.s == b.s.s) {
        if (a.f.s != b.f.s) return {};
        if (a.s.f >= b.f.f) return {{max(a.f.f,b.f.f),a.f.s},{min(a.s.f,b.s.f),a.f.s}};
        return {};
    }
    if (a.f.f == a.s.f && b.f.f == b.s.f) {
        swap(a.f.f,a.f.s); swap(a.s.f,a.s.s);
        swap(b.f.f,b.f.s); swap(b.s.f,b.s.s);
        auto v = inter(a,b); trav(t,v) swap(t.f,t.s);
        return v;
    }
    if (a.f.s != a.s.s || b.f.f != b.s.f) swap(a,b);
    if (!(a.f.s == a.s.s && b.f.f == b.s.f)) {
        ps(1,a,b);
        exit(0);
    }
    if (b.f.s <= a.f.s && a.f.s <= b.s.s && a.f.f <= b.f.f && b.f.f <= a.s.f) {
        return {{b.f.f,a.f.s}};
    }
    return {};
}

int dis(pi a, pi b) {
    if (a.f == b.f) {
        return abs(ry[a.s]-ry[b.s]);
    } else {
        if (!(a.s == b.s)) {
            ps(2,a,b);
            exit(0);
        }
        return abs(rx[a.f]-rx[b.f]);
    }
}

bool opposite(char a, char b) {
    if (a > b) swap(a,b);
    if (a == 'D' && b == 'U') return 1;
    if (a == 'L' && b == 'R') return 1;
    return 0;
}

int brute(int ind) {
    // v[ind] to v[ind+1]
    if (opposite(c[ind],c[ind-1])) return 0;
    int ret = MOD;
    F0R(i,ind) {
        vpi t = inter(seg(i),seg(ind));
        // ps("??",i,ind,seg(i),seg(ind),t);
        trav(T,t) ckmin(ret,dis(T,v[ind]));
    }
    assert(ret != MOD);
    return ret;
}

int main() {
    init();
    int lo = 0, hi = n-1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (ok(mid)) lo = mid;
        else hi = mid-1;
    }
    ll ans = 0;
    F0R(i,lo+1) ans += dist[i];
    if (lo < n-1) ans += brute(lo+1);
    ps(ans);
    // you should actually read the stuff at the bottom
}
