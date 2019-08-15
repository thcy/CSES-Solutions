#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll inf=1e18;

struct Tree {
    typedef ll T;
    static constexpr T unit = inf;
    T f(T a, T b) { return min(a, b); }
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
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n+1);
    Tree t(n+1);
    t.update(0, 0);
    rep(i, 1, n+1) {
        cin >> x[i];
        x[i]+=x[i-1];
        t.update(i, x[i]);
    }
    ll ans=-inf;
    rep(i, 1, n+1) {
        int L=max(i-b, 0);
        int R=max(i-a+1, 0);
        ans=max(ans, x[i]-t.query(L, R));
    }
    cout << ans << '\n';
    return 0;
}
