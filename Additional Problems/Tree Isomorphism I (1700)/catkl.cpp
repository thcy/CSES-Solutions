#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi h, id;
vector<vi> g;
map<int, vi> lvl;

void dfs(int i, int p) {
    trav(j, g[i])  if (j!=p) {
        dfs(j, i);
        h[i]=max(h[i], h[j]+1);
    }
    lvl[h[i]].push_back(i);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m=2*n+1;
        g.assign(m, vi());
        rep(i, 0, 2) {
            rep(j, 0, n-1) {
                int a, b;
                cin >> a >> b;
                a+=i*n, b+=i*n;
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        g[0]={1, n+1};
        h.assign(m, 0);
        id.assign(m, 0);
        lvl.clear();
        dfs(0, -1);
        if (h[1]!=h[n+1]) {
            cout << "NO\n";
            continue;
        }
        trav(l, lvl) {
            map<vector<ll>, int> u;
            trav(i, l.second) {
                vector<ll> cur;
                trav(j, g[i]) cur.push_back(3LL*n*h[j]+id[j]);
                sort(all(cur));
                if (!u.count(cur)) {
                    int s=sz(u);
                    u[cur]=s;
                }
                id[i]=u[cur];
            }
        }
        cout << (id[1]==id[n+1]? "YES\n":"NO\n");
    }
    return 0;
}
