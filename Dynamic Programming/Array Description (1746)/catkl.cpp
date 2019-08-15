#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll P=1e9+7;
void add(ll &x, ll y) {
    x+=y;
    if (x>=P) x-=P;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(m+2));
    ll ans=1;
    int cur=0;
    rep(i, 1, m+1) dp[cur][i]=1;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if(i) {
            rep(j, 1, m+1) {
                dp[cur+1][j]=dp[cur][j];
                add(dp[cur+1][j], dp[cur][j-1]);
                add(dp[cur+1][j], dp[cur][j+1]);
            }
            cur++;
        }
        if (a) {
            ans=ans*dp[cur][a]%P;
            cur=0;
            rep(j, 1, m+1)
            dp[cur][j]=(j==a);
        }
    }
    ans=ans*accumulate(all(dp[cur]), 0LL)%P;
    cout << ans << '\n';
    return 0;
}
