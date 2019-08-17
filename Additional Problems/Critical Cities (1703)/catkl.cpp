#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, r;
vector<vi> g(n+1);
vi d, p;

int dfs1(int i) {
    d[i]=1;
    p.push_back(i);
    if(i==n) return 1;
    trav(j, g[i])
    if (!d[j] && dfs1(j)) return 1;
    p.pop_back();
    return 0;
}

void dfs2(int i) {
    d[i]=r;
    trav(j, g[i]) {
        r=max(r, d[j]);
        if (d[j]==-1) dfs2(j);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int m;
    cin >> n >> m;
    g.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    d.resize(n+1);
    dfs1(1);
    d.assign(n+1, -1);
    vi ans;
    m=sz(p);
    rep(i, 0, m) d[p[i]]=i;
    rep(i, 0, m) {
        if (r<=i)
            ans.push_back(p[i]);
        dfs2(p[i]);
    }
    
    
    sort(all(ans));
    m=sz(ans);
    cout << m << '\n';
    rep(i, 0, m)
    cout << ans[i] << " \n"[i==m-1];
    return 0;
}
