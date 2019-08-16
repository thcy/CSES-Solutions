#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int P=1e9+7;

void add(int &x, int y) {
    x+=y;
    if (x>=P) x-=P;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    int M=1<<n;
    vector<vi> dp(n, vi(M));
    dp[0][1]=1;
    rep(m, 0, M) rep(i, 0, n)
    if ((m&(1<<i)) && dp[i][m])
        trav(j, g[i]) if (!(m&(1<<j)))
            add(dp[j][m^(1<<j)], dp[i][m]);
    cout << dp[n-1][M-1] << '\n';
    return 0;
}
