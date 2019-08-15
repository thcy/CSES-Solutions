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
    
    int n;
    cin >> n;
    vi dp(n+1, n);
    dp[0]=0;
    rep(i, 1, n+1) {
        for(int j=i; j; j/=10)
            dp[i]=min(dp[i], dp[i-j%10]+1);
    }
    cout << dp[n] << '\n';
    return 0;
}
