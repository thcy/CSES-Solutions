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
    string s;
    cin >> s;
    int n=sz(s);
    vector<vi> dp(n+1, vi(n+1));
    vector<vi> B(n, vi(n));
    rep(i, 0, n) {
        B[i][0]=1;
        rep(j, 1, i+1) B[i][j]=(B[i-1][j]+B[i-1][j-1])%P;
    }
    rep(i, 0, n+1) dp[i][i]=1;
    for(int l=2; l<=n; l+=2) rep(i, 0, n-l+1) {
        for(int k=i+1; k<i+l; k+=2) {
            if (s[k]!=s[i]) continue;
            int t=1LL*dp[i+1][k]*dp[k+1][i+l]%P;
            t=1LL*t*B[l/2][(k-i+1)/2]%P;
            dp[i][i+l]=(dp[i][i+l]+t)%P;
        }
    }
    cout << dp[0][n] << '\n';
    return 0;
}
