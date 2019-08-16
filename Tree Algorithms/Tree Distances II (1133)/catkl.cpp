#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> g;
vector<ll> s, d;

ll dfs1(int i, int p) {
    ll cd=0;
    s[i]++;
    trav(j, g[i]) if (j!=p) {
        cd+=dfs1(j, i)+s[j];
        s[i]+=s[j];
    }
    return cd;
}

void dfs2(int i, int p, ll cd) {
    d[i]=cd;
    trav(j, g[i]) if (j!=p)
        dfs2(j, i, cd+n-2*s[j]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    cin >> n;
    g.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s.resize(n+1);
    d.resize(n+1);
    ll d1=dfs1(1, 0);
    dfs2(1, 0, d1);
    rep(i, 1, n+1)
    cout << d[i] << " \n"[i==n];
    return 0;
}
