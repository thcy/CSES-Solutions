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
ll dist[2][MX];
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

void gendist2() {
    FOR(i,1,n) dist[1][i] = INF;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,n});
    while (sz(pq)) {
        pll x = pq.top(); pq.pop();
        if (dist[1][x.s] != x.f) continue;
        for (auto a: radj[x.s]) if (dist[1][a.f] > x.f+a.s)
            pq.push({dist[1][a.f] = x.f+a.s,a.f});
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c}), radj[b].pb({a,c});
    }
    gendist1();
    gendist2();
    FOR(i,1,n+1) if (dist[0][i] != INF)
        for (auto a: adj[i]) if (dist[1][a.f] != INF)
            ans = min(ans,dist[0][i]+dist[1][a.f]+a.s/2);
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
