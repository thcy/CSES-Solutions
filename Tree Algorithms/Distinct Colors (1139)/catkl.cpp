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
vector<set<int>> x;
vi c, ans;

void dfs(int i, int p) {
    x[i].insert(c[i]);
    trav(j, g[i]) if (j!=p) {
        dfs(j, i);
        if (sz(x[j])>sz(x[i]))
            swap(x[i], x[j]);
    }
    trav(j, g[i]) if (j!=p)
        trav(k, x[j]) x[i].insert(k);
    ans[i]=sz(x[i]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    c.resize(n+1);
    rep(i, 1, n+1) cin >> c[i];
    g.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    x.resize(n+1);
    ans.resize(n+1);
    dfs(1, 0);
    rep(i, 1, n+1)
    cout << ans[i] << " \n"[i==n];
    return 0;
}
