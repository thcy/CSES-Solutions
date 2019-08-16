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

ll n,ans;

int main() {
    cin >> n;
    for (ll i = 1; i <= 1000000; ++i) {
        if (n/i <= 1000000) break;
        ans += (n/i)*i;
        ans %= MOD;
    }
    FOR(j,1,1000001) {
        ll x = n/j, y = n/(j+1);
        // y+1 to x
        __int128 t = (x+y+1) % MOD;
        t = t*(x-y) % MOD;
        t = t*(MOD+1)/2 % MOD;
        t = t*j % MOD;
        ans = (ans+t) % MOD;
    }
    cout << ans;
}
