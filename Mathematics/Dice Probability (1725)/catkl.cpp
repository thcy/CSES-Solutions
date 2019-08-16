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
    
    typedef long double dbl;
    int n, a, b;
    cin >> n >> a >> b;
    vector<dbl> dp(b+1);
    dp[0]=1;
    rep(i, 0, n) {
        for(int j=b; j>=0; j--) {
            dp[j]=0;
            rep(k, 1, 7) if (j>=k) dp[j]+=dp[j-k];
        }
    }
    dbl ans=0;
    rep(i, a, b+1) ans+=dp[i];
    cout << fixed << setprecision(6);
    cout << ans/pow(6, n) << '\n';
    return 0;
}
