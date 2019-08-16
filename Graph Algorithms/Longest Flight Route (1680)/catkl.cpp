#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topo_sort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    trav(li, gr) trav(x, li) indeg[x]++;
    queue<int> q; // use priority queue for lexic. smallest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
    while (!q.empty()) {
        int i = -q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        trav(x, gr[i])
        if (--indeg[x] == 0) q.push(-x);
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+1);
    while (m--) {
        int a, b;
        cin >> a >>b;
        g[a].push_back(b);
    }
    vi o=topo_sort(g), dp(n+1), p(n+1);
    dp[1]=1;
    trav(i, o) trav(j, g[i])
    if (dp[i] && dp[i]+1>dp[j])
        dp[j]=dp[i]+1, p[j]=i;
    int d=dp[n];
    if (!d) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << d << "\n";
    vi ans;
    for (int i=n; i; i=p[i])
        ans.push_back(i);
    rep(i, 0, d)
    cout  << ans[d-1-i] << " \n"[i==d-1];
    return 0;
}
