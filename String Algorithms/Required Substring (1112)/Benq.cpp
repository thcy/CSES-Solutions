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
string s;
int nex[100][26];
array<int,101> dp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    F0R(i,sz(s)) {
        string t = s.substr(0,i);
        F0R(j,26) {
            string T = t+char('A'+j);
            while (T != s.substr(0,sz(T))) T = T.substr(1,sz(T)-1);
            nex[i][j] = sz(T);
        }
    }
    dp[0] = 1;
    F0R(i,n) {
        array<int,101> DP = array<int,101>();
        F0R(j,sz(s)) F0R(k,26) DP[nex[j][k]] = (DP[nex[j][k]]+dp[j]) % MOD;
        DP[sz(s)] = 0;
        dp = DP;
    }
    ll ans = 1; F0R(i,n) ans = 26*ans % MOD;
    F0R(i,sz(s)) ans = (ans+MOD-dp[i]) % MOD;
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
