#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
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
const ll INF = 1e18;

vector<pii> adj[MX], radj[MX];
ll dist[2][MX], num[MX], mx[MX], mn[MX];
ll ans = INF;
int n,m;

void gendist1() {
    FOR(i,2,n+1) dist[0][i] = INF;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    while (sz(pq)) {
        pll x = pq.top(); pq.pop();
        if (dist[0][x.s] != x.f) continue;
        for (auto a: adj[x.s]) if (dist[0][a.f] > x.f+a.s)
            pq.push({dist[0][a.f] = x.f+a.s,a.f});
    }
}

bool cmp(int a, int b) {
    return dist[0][a] < dist[0][b];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    gendist1();
    vi x; FOR(i,1,n+1) x.pb(i);
    sort(x.rbegin(),x.rend(),cmp);
    num[n] = 1;
    for (int i: x) if (i != n) {
        mx[i] = -MOD, mn[i] = MOD;
        for (auto j: adj[i]) if (dist[0][i]+j.s == dist[0][j.f]) {
            num[i] = (num[i]+num[j.f]) % MOD;
            mx[i] = max(mx[i],mx[j.f]+1);
            mn[i] = min(mn[i],mn[j.f]+1);
        }
    }
    cout << dist[0][n] << " " << num[1] << " " << mn[1] << " " << mx[1];
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
