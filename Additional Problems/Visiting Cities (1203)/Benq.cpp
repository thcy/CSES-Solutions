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
ll dist[2][MX], num[MX], NUM[MX];
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
        radj[b].pb({a,c});
    }
    gendist1();
    vi x; FOR(i,1,n+1) x.pb(i);
    sort(x.rbegin(),x.rend(),cmp);
    num[n] = 1;
    for (int i: x) if (i != n) {
        for (auto j: adj[i]) if (dist[0][i]+j.s == dist[0][j.f]) {
            num[i] = (num[i]+num[j.f]) % MOD;
        }
    }
    NUM[1] = 1;
    reverse(all(x));
    for (int i: x) if (i != 1) {
        for (auto j: radj[i]) if (dist[0][i] == dist[0][j.f]+j.s) {
            NUM[i] = (NUM[i]+NUM[j.f]) % MOD;
        }
    }
    vi ans;
    FOR(i,1,n+1) if ((NUM[i]*num[i]) % MOD == num[1]) ans.pb(i);
    cout << sz(ans) << "\n";
    for (int i: ans) cout << i << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
