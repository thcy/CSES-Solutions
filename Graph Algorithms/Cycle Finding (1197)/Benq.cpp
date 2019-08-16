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

const ll INF = 1e18;
const int MX = 2501;

int n,m,q,s,pre[MX];
vector<pair<pii,int>> edge;
ll dist[MX];
vi z;
bool vis[MX];

void backtrack(int x) {
    while (!vis[x]) {
        z.pb(x); vis[x] = 1;
        x = pre[x];
    }
    z.pb(x);
    reverse(all(z));
    while (z.back() != z.front()) z.pop_back();
    for (int i: z) cout << i << " ";
}

void solve() {
    edge.clear();
    FOR(i,1,n+1) dist[i] = 0;
    F0R(i,m) {
        int u,v,w; cin >> u >> v >> w;
        if (u == v && w < 0) {
            cout << "YES\n";
            cout << u << " " << v << "\n";
            return;
        }
        edge.pb({{u,v},w});
    }
    FOR(i,1,n+1) for (auto a: edge)
        if (dist[a.f.f] < INF) {
            ll t = dist[a.f.f]+a.s;
            if (t < dist[a.f.s]) {
                dist[a.f.s] = t;
                pre[a.f.s] = a.f.f;
            }
        }
    
    for (auto a: edge)
        if (dist[a.f.s] > dist[a.f.f]+a.s) {
            cout << "YES\n";
            backtrack(a.f.s);
            return;
        }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    solve();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
