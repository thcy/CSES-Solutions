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
int fail;
vi p;

void dfs(int i, int cur) {
    p[i]=cur;
    trav(j, g[i]) {
        if (p[j]==p[i]) fail=1;
        if (!p[j]) dfs(j, cur^3);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    p.resize(n+1);
    rep(i, 1, n+1) if (!p[i])
        dfs(i, 1);
    if (fail)
        cout << "IMPOSSIBLE\n";
    else
        rep(i, 1, n+1) cout << p[i] << " \n"[i==n];
    return 0;
}
