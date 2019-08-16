#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll inf=1e10;
struct Node {
    ll l, r, m, s;
    Node(ll l, ll r, ll m, ll s)
    : l(l), r(r), m(m), s(s) {}
    Node(ll s) : l(s), r(s), m(s), s(s) {};
};
Node unit(-inf);

template<class T>
struct Tree {
    T f(T a, T b) {
        ll L=max(a.l, a.s+b.l);
        ll R=max(b.r, b.s+a.r);
        ll M=max(max(a.m, b.m), a.r+b.l);
        return Node(L, R, M, a.s+b.s);
    }
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

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    Tree<Node> t(n);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        t.update(i, a);
    }
    rep(i, 0, q) {
        ll a, b;
        cin >> a >> b;
        t.update(a-1, Node(b));
        cout << t.query(0, n).m << '\n';
    }
    return 0;
}
