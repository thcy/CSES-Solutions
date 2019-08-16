#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T, int N, ll P> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
        rep(k,0,N)
        a.d[i][j] = (a.d[i][j] + d[i][k]*m.d[k][j]) % P;
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N)
        ret[i] = (ret[i]  + d[i][j] * vec[j]) % P;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
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
    constexpr ll P=1e9+7;
    Matrix<ll, N, P> x;
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int a, b;
        cin >> a >> b;
        x.d[a][b]++;
    }
    cout << (x^k).d[1][n] << '\n';
    return 0;
}
