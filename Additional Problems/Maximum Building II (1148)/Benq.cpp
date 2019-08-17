#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
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
const int MX = 1002;

int n,m, cur[MX],ans[MX][MX];
pii tmp[MX][MX];
char g[MX][MX];

pii operator+(pii a, pii b) {
    return {a.f+b.f,a.s+b.s};
}

pii operator-(pii a, pii b) {
    return {a.f-b.f,a.s-b.s};
}

void upd(int x, int l, int r, pii val) {
    tmp[x][l] = tmp[x][l] + val;
    tmp[x][r+1] = tmp[x][r+1] - val;
}

void ins(int x, int l, int r) {
    if (l > r) swap(l,r);
    
    upd(x,1,l-1,{1,0});
    upd(x,l,r,{0,l});
    upd(x,r+1,l+r-1,{-1,l+r});
}

void solve(int x) {
    vector<pii> v;
    F0R(i,n) v.pb({cur[i]-x,i});
    sort(v.rbegin(),v.rend());
    
    set<int> bad;
    FOR(i,-1,n+1) bad.insert(i);
    for (pii x: v) {
        auto it = bad.find(x.s);
        ins(x.f,x.s-*prev(it),*next(it)-x.s);
        bad.erase(it);
    }
}

void propagate(int x) {
    FOR(i,1,n+1) {
        tmp[x][i] = tmp[x][i]+tmp[x][i-1];
        ans[x][i] = tmp[x][i].f*i+tmp[x][i].s;
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
    FOR(j,1,m+1) propagate(j);
    FORd(j,1,m) FOR(i,1,n+1) ans[j][i] += ans[j+1][i];
    FOR(i,1,n+1) {
        FOR(j,1,m+1) cout << ans[j][i] << " ";
        cout << "\n";
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
