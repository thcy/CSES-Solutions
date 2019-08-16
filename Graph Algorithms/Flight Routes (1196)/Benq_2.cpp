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

int n,m,k;
priority_queue<ll> bes[MX];
vector<pii> adj[MX];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    
    bes[1].push(0);
    pq.push({0,1});
    
    while (sz(pq)) {
        auto a = pq.top(); pq.pop();
        if (a.f > bes[a.s].top()) continue;
        for (auto i: adj[a.s]) {
            ll tmp = a.f+i.s;
            if (sz(bes[i.f]) < k || tmp < bes[i.f].top()) {
                bes[i.f].push(tmp);
                pq.push({tmp,i.f});
                if (sz(bes[i.f]) > k) bes[i.f].pop();
            }
        }
    }
    
    vector<ll> ans;
    F0R(i,k) {
        ans.pb(bes[n].top());
        bes[n].pop();
    }
    reverse(all(ans));
    for (auto a: ans) cout << a << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
