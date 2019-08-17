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

int n;
ll dp[1001][1000][2];

void gen(int ind) {
    F0R(i,ind-1) F0R(j,2) {
        dp[ind-1][i][j] %= MOD;
        // place it next to prev
        // between previous two
        
        if (j) {
            dp[ind][i][1] += dp[ind-1][i][j];
            dp[ind][i+1][1] += dp[ind-1][i][j];
        } else {
            dp[ind][i][1] += 2*dp[ind-1][i][j];
        }
        
        // not between previous two
        // not place it between
        // place it between
        if (i) dp[ind][i-1+j][0] += i*dp[ind-1][i][j];
        if (ind-i-2 > 0) dp[ind][i+j][0] += (ind-i-2)*dp[ind-1][i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[1][0][0] = 1;
    FOR(i,2,1001) gen(i);
    int n; cin >> n;
    cout << (dp[n][0][0] % MOD) << "\n";
    // F0R(i,n-1) cout << dp[n][i][0] << " " << dp[n][i][1] << "\n";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
