#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = -1, sz[i] = 1;
    }
    
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y], par[y] = x;
        return 1;
    }
};

int n,m, cur[1000];
char g[1000][1000];
ll ans = 0;

void solve(int x) {
    vector<pii> v;
    F0R(i,n) v.pb({cur[i]-x,i});
    sort(v.rbegin(),v.rend());
    
    DSU<1000> D = DSU<1000>();
    for (auto a: v) {
        D.par[a.s] = a.s;
        if (a.s > 0 && D.par[a.s-1] != -1) D.unite(a.s,a.s-1);
        if (a.s < n-1 && D.par[a.s+1] != -1) D.unite(a.s,a.s+1);
        ans = max(ans,a.f*(ll)D.sz[D.get(a.s)]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) F0R(j,m) cin >> g[i][j];
    F0R(i,n) cur[i] = m;
    F0Rd(j,m) {
        F0R(i,n) if (g[i][j] == '*') cur[i] = j;
        solve(j);
    }
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
