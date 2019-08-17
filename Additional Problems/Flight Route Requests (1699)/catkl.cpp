#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    trav(e,g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));
    
    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n), gu(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        gu[a].push_back(b);
        gu[b].push_back(a);
    }
    vi bs(n);
    scc(g, [&](vi &c) {
        if (sz(c)==1) return;
        trav(i, c) bs[i]=1;
    });
    int ans=n;
    scc(gu, [&](vi &c) {
        ans--;
        trav(i, c) if (bs[i]) {
            ans++;
            return;
        }
    });
    cout << ans <<'\n';
    return 0;
}
