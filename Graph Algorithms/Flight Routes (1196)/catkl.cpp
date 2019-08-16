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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> g(n+1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vi cnt(n+1);
    typedef pair<ll, int> T;
    priority_queue<T, vector<T>, greater<T>> q;
    for(q.push({0, 1}); !q.empty(); q.pop()) {
        ll d=q.top().first;
        int i=q.top().second;
        if (cnt[i]==k) continue;
        cnt[i]++;
        if (i==n) {
            cout << d << " \n"[cnt[n]==k];
            if (cnt[n]==k) return 0;
        }
        trav(p, g[i]) q.push({d+p.second, p.first});
    }
    return 0;
}
