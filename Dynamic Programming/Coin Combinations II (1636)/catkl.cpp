#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int P=1e9+7;
    int n, x;
    cin >> n >> x;
    vi dp(x+1);
    dp[0]=1;
    rep(i, 0, n) {
        int a;
        cin >> a;
        rep(j, a, x+1) {
            dp[j]+=dp[j-a];
            if (dp[j]>=P) dp[j]-=P;
        }
    }
    cout << dp[x] << '\n';
    return 0;
}
