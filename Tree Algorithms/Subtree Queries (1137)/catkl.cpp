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

int ct=0;
vector<vi> g;
vi L, R;

void dfs(int i, int p) {
    L[i]=ct++;
    trav(j, g[i])
    if(j!=p) dfs(j, i);
    R[i]=ct;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    g.resize(n);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    L.resize(n);
    R.resize(n);
    dfs(0, -1);
    Tree t(n);
    rep(i, 0, n) t.update(L[i], v[i]);
    while (q--) {
        int type;
        cin >> type;
        if (type==1) {
            int a, b;
            cin >> a >> b;
            a--;
            t.update(L[a], b);
        }
        else {
            int a;
            cin >> a;
            a--;
            cout << t.query(L[a], R[a]) << '\n';
        }
    }
    return 0;
}
