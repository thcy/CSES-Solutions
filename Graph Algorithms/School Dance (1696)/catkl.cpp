#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    trav(e, g[di])
    if (!vis[e] && find(e, g, btoa, vis)) {
        btoa[e] = di;
        return 1;
    }
    return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i,0,sz(g)) {
        vis.assign(sz(btoa), 0);
        trav(j,g[i])
        if (find(j, g, btoa, vis)) {
            btoa[j] = i;
            break;
        }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> g(n);
    while (k--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    vi btoa(m, -1);
    cout << dfsMatching(g, btoa) << '\n';
    rep(i, 0, m) if (btoa[i]>=0)
        cout << btoa[i]+1 << " " << i+1 << '\n';
    return 0;
}
