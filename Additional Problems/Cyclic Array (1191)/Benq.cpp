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

ll n, k, sum;
int x[1000000], nex[20][1000000], ans = MOD;

int get(int z) {
    int cur = 0;
    int Z = z;
    F0Rd(i,20) {
        if (nex[i][Z] < z+n) {
            Z = nex[i][Z];
            cur ^= (1<<i);
        }
    }
    return cur+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n) {
        cin >> x[i];
        x[i+n] = x[i];
    }
    int sum = 0, r = -1;
    F0R(i,2*n) {
        while (r < 2*n-2 && sum+x[r+1] <= k) sum += x[++r];
        nex[0][i] = r+1;
        sum -= x[i];
    }
    FOR(i,1,20) F0R(j,2*n) nex[i][j] = nex[i-1][nex[i-1][j]];
    F0R(i,n) ans = min(ans,get(i));
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
