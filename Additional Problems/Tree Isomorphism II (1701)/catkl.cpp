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

int isomorphic() {
    int m=sz(g);
    h.assign(m, 0);
    id.assign(m, 0);
    lvl.clear();
    dfs(0, -1);
    if (h[g[0][0]]!=h[g[0][1]])
        return 0;
    trav(l, lvl) {
        map<vector<ll>, int> u;
        trav(i, l.second) {
            vector<ll> cur;
            trav(j, g[i])
            cur.push_back(1LL*m*h[j]+id[j]);
            sort(all(cur));
            if (!u.count(cur)) {
                int s=sz(u);
                u[cur]=s;
            }
            id[i]=u[cur];
        }
    }
    return id[g[0][0]]==id[g[0][1]];
}

vi getcore(int w) {
    int m=sz(g), n=m/2, r=n*w+1;
    vi d(m), q, ans;
    rep(i, r, r+n) {
        d[i]=sz(g[i]);
        if (d[i]==1)
            d[i]=-1, q.push_back(i);
    }
    rep(L, 0, sz(q)) trav(j, g[q[L]])
    if (d[j]>0 && --d[j]==1)
        d[j]=d[q[L]]-1, q.push_back(j);
    do {
        ans.push_back(q[--n]);
    } while (n && d[q[n]]==d[q[n-1]]);
    return ans;
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
        vi core[2];
        rep(i, 0, 2) {
            rep(j, 0, n-1) {
                int a, b;
                cin >> a >> b;
                a+=i*n, b+=i*n;
                g[a].push_back(b);
                g[b].push_back(a);
            }
            core[i]=getcore(i);
        }
        int ok=0;
        if (sz(core[0])==sz(core[1])) {
            trav(r0, core[0]) trav(r1, core[1]) {
                g[0]={r0, r1};
                if ((ok=isomorphic())) goto out;
            }
        }
    out:
        cout << (ok? "YES\n" : "NO\n");
    }
    return 0;
}
