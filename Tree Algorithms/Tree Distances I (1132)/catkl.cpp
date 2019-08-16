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
vector<pii> d1, d2;
vi ans;

void dfs1(int i, int p) {
    trav(j, g[i]) if (j!=p) {
        dfs1(j, i);
        d2[i]=max(d2[i], {1+d1[j].first, j});
        if (d2[i]>d1[i]) swap(d1[i], d2[i]);
    }
}

void dfs2(int i, int p, int d) {
    ans[i]=max(d1[i].first, d);
    trav(j, g[i]) if (j!=p) {
        if (j==d1[i].second)
            dfs2(j, i, 1+max(d2[i].first, d));
        else dfs2(j, i, 1+ans[i]);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    g.resize(n+1);
    d1.resize(n+1);
    d2.resize(n+1);
    ans.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    rep(i, 1, n+1)
    cout << ans[i] << " \n"[i==n];
    return 0;
}
