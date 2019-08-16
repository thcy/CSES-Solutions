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
const int MX = 500001;

int n, par[MX], sub[MX];
ll ans[MX];
vi adj[MX];

void dfs(int x) {
    sub[x] = 1;
    for (int i: adj[x]) if (i != par[x]) {
        par[i] = x;
        dfs(i);
        sub[x] += sub[i];
    }
}

void dfs2(int x, int dis = 0) {
    ans[1] += dis;
    for (int i: adj[x]) if (i != par[x]) dfs2(i,dis+1);
}

void dfs3(int x) {
    for (int i: adj[x]) if (i != par[x]) {
        ans[i] = ans[x]+(n-sub[i])-sub[i];
        dfs3(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1);
    dfs2(1);
    dfs3(1);
    FOR(i,1,n+1) cout << ans[i] << "\n";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
