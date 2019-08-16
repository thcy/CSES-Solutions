#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    
    RMQ(const vector<T>& V) {
        int N = sz(V), on = 1, depth = 1;
        while (on < N) on *= 2, depth++;
        jmp.assign(depth, V);
        rep(i,0,depth-1) rep(j,0,N)
        jmp[i+1][j] = min(jmp[i][j],
                          jmp[i][min(N - 1, j + (1 << i))]);
    }
    
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    RMQ<int> rmq(x);
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        cout << rmq.query(a-1, b) << '\n';
    }
    return 0;
}
