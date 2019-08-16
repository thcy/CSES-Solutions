#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+1);
    while    (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi p(n+1);
    p[1]=-1;
    queue<int> q;
    for (q.push(1); !q.empty(); q.pop()) {
        int i=q.front();
        trav(j, g[i]) if (!p[j])
            p[j]=i, q.push(j);
    }
    if (!p[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi ans;
    for (int i=n; i>0; i=p[i])
        ans.push_back(i);
    reverse(all(ans));
    cout << sz(ans) << '\n';
    rep(i, 0, sz(ans))
    cout << ans[i] << " \n"[i==sz(ans)-1];
    return 0;
}
