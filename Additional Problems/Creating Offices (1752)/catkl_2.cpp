#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

constexpr int inf=1e9;
int n, d;
vector<vi> g;
vi lvl, h, s, ans;

void dfs(int i, int p, int clvl) {
    lvl[i]=clvl;
    h[i]=inf;
    s[i]=i;
    trav(j, g[i]) if(j!=p) {
        dfs(j, i, clvl+1);
        if (s[j]) {
            if ((lvl[s[j]]-lvl[i])*2>=d)
                ans.push_back(s[j]), h[j]=lvl[s[j]];
            else if(lvl[s[j]]>lvl[s[i]])
                s[i]=s[j];
        }
        h[i]=min(h[i], h[j]);
    }
    if (lvl[s[i]]+h[i]-2*lvl[i]<d)
        s[i]=0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    cin >> n >> d;
    g.resize(n+1);
    lvl.resize(n+1);
    h.resize(n+1);
    s.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    if (s[1]) ans.push_back(s[1]);
    cout << sz(ans) << '\n';
    rep(i, 0, sz(ans))
    cout << ans[i] << " \n"[i==sz(ans)-1];
    return 0;
}
