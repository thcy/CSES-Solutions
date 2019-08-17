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

vi cover(vector<vi>& g, int n, int m) {
    vi match(m, -1);
    int res = dfsMatching(g, match);
    vector<bool> lfound(n, true), seen(m);
    trav(it, match) if (it != -1) lfound[it] = false;
    vi q, cover;
    rep(i,0,n) if (lfound[i]) q.push_back(i);
    while (!q.empty()) {
        int i = q.back(); q.pop_back();
        lfound[i] = 1;
        trav(e, g[i]) if (!seen[e] && match[e] != -1) {
            seen[e] = true;
            q.push_back(match[e]);
        }
    }
    rep(i,0,n) if (!lfound[i]) cover.push_back(i);
    rep(i,0,m) if (seen[i]) cover.push_back(n+i);
    assert(sz(cover) == res);
    return cover;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vector<vi> g(n);
    string s;
    rep(i, 0, n) {
        cin >> s;
        rep(j, 0, n) if (s[j]=='o') g[i].push_back(j);
    }
    vi r=cover(g, n, n);
    cout << sz(r) << '\n';
    trav(i, r)
    cout << i/n+1 << " " << i%n+1 << '\n';
    return 0;
}
