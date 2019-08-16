#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> g;
vi u;

void dfs(int i, int p) {
    u[i]=1;
    trav(j, g[i]) if (j!=p) {
        dfs(j, i);
        u[i]&=!u[j];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    g.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    u.resize(n+1);
    dfs(1, 0);
    cout << n-accumulate(all(u), 0) << '\n';
    return 0;
}
