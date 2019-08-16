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
const int MX = 200001;

int n,q,t[MX], ind[MX], depth[MX], comp[MX], nex[MX];
int tmp[MX], par[MX][18];
vi child[MX], adj[MX];
bool incyc[MX];

// not in cyc, not in cyc
// not in cyc, in cyc
// in cyc, not in cyc
// in cyc, in cyc

void dfs(int x) {
    int X = x;
    while (tmp[x] == 0) {
        tmp[x] = X;
        x = t[x];
    }
    while (tmp[x] == X) {
        tmp[x] = X+n; ind[x] = nex[comp[x]]++;
        incyc[x] = 1;
        x = t[x];
    }
}

void DFS(int cur) {
    for (int i: child[cur]) if (!incyc[i]) {
        depth[i] = depth[cur]+1;
        DFS(i);
    }
}

void process() {
    FOR(i,1,n+1) dfs(i);
    FOR(i,1,n+1) par[i][0] = t[i];
    FOR(i,1,18) FOR(j,1,n+1)
    par[j][i] = par[par[j][i-1]][i-1];
    FOR(i,1,n+1) if (incyc[i]) DFS(i);
}

int getPar(int a, int b) {
    F0Rd(i,18) if (b&(1<<i)) a = par[a][i];
    return a;
}

void gencomp(int x, int i) {
    if (comp[x]) return;
    comp[x] = i;
    for (int y: adj[x]) gencomp(y,i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(i,1,n+1) {
        cin >> t[i];
        child[t[i]].pb(i);
        adj[i].pb(t[i]), adj[t[i]].pb(i);
    }
    FOR(i,1,n+1) if (comp[i] == 0) gencomp(i,i);
    process();
    F0R(i,q) {
        int a,b; cin >> a >> b;
        if (comp[a] != comp[b]) {
            cout << "-1\n";
            continue;
        }
        if (!incyc[a]) {
            if (incyc[b]) {
                int x = getPar(a,depth[a]);
                cout << ((ind[b]-ind[x]+nex[comp[a]])%nex[comp[a]])+depth[a];
            } else {
                if (getPar(a,depth[a]-depth[b]) == b) cout << depth[a]-depth[b];
                else cout << -1;
            }
        } else {
            if (incyc[b]) cout << (ind[b]-ind[a]+nex[comp[a]])%nex[comp[a]];
            else cout << -1;
        }
        cout << "\n";
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
