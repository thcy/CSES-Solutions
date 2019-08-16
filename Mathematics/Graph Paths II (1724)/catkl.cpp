#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll inf=2e18;
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d;
    Matrix() {
        rep(i, 0, N) rep(j, 0, N)
        d[i][j] = inf;
    }
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
        rep(k,0,N)
        a.d[i][j] = min(a.d[i][j], d[i][k]+m.d[k][j]);
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N, inf);
        rep(i,0,N) rep(j,0,N)
        ret[i] = min(ret[i], d[i][j] + vec[j]);
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i]=0;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int N=101;
    Matrix<ll, N> x;
    ll n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        x.d[a][b]=min(x.d[a][b], c);
    }
    ll ans=(x^k).d[1][n];
    cout << (ans==inf? -1:ans) << '\n';
    return 0;
}
