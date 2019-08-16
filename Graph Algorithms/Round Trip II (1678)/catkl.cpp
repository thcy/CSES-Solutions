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
vi v, s{0}, ans;

int dfs(int i) {
    v[i]=sz(s);
    s.push_back(i);
    trav(j, g[i]) {
        if (v[j]>0) {
            ans=vi(begin(s)+v[j], end(s));
            return 1;
        }
        if (v[j]==0 && dfs(j))
            return 1;
    }
    v[i]=-1;
    s.pop_back();
    return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    v.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    rep(i, 1, n+1)
    if (v[i]==0 && dfs(i)) break;
    if (!sz(ans))
        cout << "IMPOSSIBLE\n";
    else {
        cout << sz(ans)+1 << '\n';
        trav(i, ans) cout << i << " ";
        cout << ans[0] << '\n';
    }
    return 0;
}
