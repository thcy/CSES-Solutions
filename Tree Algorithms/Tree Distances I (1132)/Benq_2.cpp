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

int n, dist[MX], ans[MX];
vi adj[MX];

void dfs(int cur, int pre) {
    for (int i: adj[cur]) if (i != pre) {
        dist[i] = dist[cur]+1;
        dfs(i,cur);
    }
}

void dfs(int cur) {
    memset(dist,0,sizeof dist);
    dfs(cur,-1);
}

void treeDiameter() {
    dfs(1);
    int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    dfs(bes); FOR(i,1,n+1) ans[i] = dist[i];
    FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    dfs(bes); FOR(i,1,n+1) ans[i] = max(ans[i],dist[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    treeDiameter();
    FOR(i,1,n+1) cout << ans[i] << " ";
}
