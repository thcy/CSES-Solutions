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
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2;)
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
    int lower_bound(T val) {
        int pos=1;
        while (pos<n) pos=2*pos+(s[2*pos]<val);
        return pos-n;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int inf=1e9;
    int n, m;
    cin >> n >> m;
    int N=1;
    while (N<=n) N*=2;
    Tree t(N, 0);
    rep(i, 0, n) {
        int a;
        cin >> a;
        t.update(i, a);
    }
    t.update(n, inf);
    while (m--) {
        int a;
        cin >> a;
        int i=t.lower_bound(a);
        if (i==n) cout << "0\n";
        else {
            cout << i+1 << '\n';
            t.update(i, -a);
        }
    }
    return 0;
}
