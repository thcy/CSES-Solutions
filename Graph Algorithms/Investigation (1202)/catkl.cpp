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
    
    constexpr ll inf=1e18;
    constexpr int P=1e9+7;
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n+1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vector<ll> d(n+1, inf);
    priority_queue<pair<ll, int>> q;
    vi o;
    for (q.push({0, 1}); !q.empty(); q.pop()) {
        ll cur=-q.top().first;
        int i=q.top().second;
        if (d[i]<inf) continue;
        d[i]=cur;
        o.push_back(i);
        trav(p, g[i]) q.push({-cur-p.second, p.first});
    }
    vi cnt(n+1), sp(n+1, n), lp(n+1);
    cnt[1]=1,  sp[1]=lp[1]=0;
    trav(i, o) trav(p, g[i]) {
        int j=p.first;
        if (d[i]+p.second!=d[j]) continue;
        cnt[j]+=cnt[i];
        if(cnt[j]>=P) cnt[j]-=P;
        sp[j]=min(sp[j], 1+sp[i]);
        lp[j]=max(lp[j], 1+lp[i]);
    }
    cout << d[n] << " " << cnt[n] << " " << sp[n] << " " << lp[n] << '\n';
    return 0;
}
