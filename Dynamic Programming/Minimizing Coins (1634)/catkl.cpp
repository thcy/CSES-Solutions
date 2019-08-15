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
    
    constexpr int inf=1e9;
    int n, x;
    cin >> n >> x;
    vi dp(x+1, inf);
    dp[0]=0;
    while (n--) {
        int a;
        cin >> a;
        rep(i, 0, x-a+1)
        dp[i+a]=min(dp[i+a], dp[i]+1);
    }
    cout << (dp[x]==inf? -1:dp[x]) << '\n';
    return 0;
}
