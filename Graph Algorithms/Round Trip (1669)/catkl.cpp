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
vi s{0}, si, ans;

int dfs(int i, int p) {
    si[i]=sz(s);
    s.push_back(i);
    trav(j, g[i]) if (j!=p) {
        int w=si[j];
        if (w) {
            s.push_back(j);
            ans=vi(begin(s)+w, end(s));
            return 1;
        }
        if (dfs(j, i)) return 1;
    }
    s.pop_back();
    return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    si.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, 1, n+1) if (!si[i] && dfs(i, 0)) {
        m=sz(ans);
        cout << m << '\n';
        rep(i, 0, m)
        cout << ans[i] << " \n"[i==m-1];
        return 0;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
