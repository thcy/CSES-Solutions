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
    constexpr int P2=(P+1)/2;
    int n;
    cin >> n;
    int m=n*(n+1)/2;
    if (m%2) {
        cout << 0 <<'\n';
        return 0;
    }
    m/=2;
    vi dp(m+1);
    dp[0]=1;
    rep(i, 1, n+1) for(int j=m; j>=i; j--) {
        dp[j]+=dp[j-i];
        if (dp[j]>=P) dp[j]-=P;
    }
    cout << 1LL*dp[m]*P2%P << '\n';
    return 0;
}
