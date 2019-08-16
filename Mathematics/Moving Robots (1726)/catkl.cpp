#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int N=8;
    constexpr int M=N*N;
    vector<vi> g(M);
    rep(i, 0, N) rep(j, 0, N)
    rep(ii, i-1, i+2) rep(jj, j-1, j+2) {
        if (abs(i-ii)+abs(j-jj)!=1) continue;
        if (ii<0 || ii==N || jj<0 || jj==N) continue;
        g[N*i+j].push_back(N*ii+jj);
    }
    vector<long double> ans(M, 1), x(M), y(M);
    int n;
    cin >> n;
    rep(s, 0, M) {
        rep(i, 0, M) x[i]=(i==s);
        rep(k, 0, n) {
            y.assign(M, 0);
            rep(i, 0, M) trav(j, g[i])
            y[j]+=x[i]/sz(g[i]);
            swap(x, y);
        }
        rep(i, 0, M) ans[i]*=1-x[i];
    }
    cout << fixed << setprecision(6);
    cout << accumulate(all(ans), 0.0) << '\n';
    return 0;
}
