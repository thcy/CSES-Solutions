#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N=101;
constexpr int X=5001;
constexpr int P=1e9+7;
int dp[2][N][X], t[N];

void add(int &a, int b) {
    a+=b;
    if(a>=P) a-=P;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, x;
    cin >> n >> x;
    rep(i, 0, n) cin >> t[i];
    sort(t, t+n);
    int c=0, p=1;
    dp[p][0][0]=1;
    rep(i, 0, n) {
        rep(y, 0, x+1) rep(k, 0, i+1)
        dp[c][k][y]=0;
        rep(k, 0, i+1) {
            int d=(i? k*(t[i]-t[i-1]) : 0);
            rep(y, 0, x+1-d) if (dp[p][k][y]) {
                int val=dp[p][k][y];
                add(dp[c][k][y+d], val);
                add(dp[c][k+1][y+d], val);
                val=1LL*val*k%P;
                if (k) add(dp[c][k-1][y+d], val);
                add(dp[c][k][y+d], val);
            }
        }
        swap(c, p);
    }
    int ans=0;
    rep(y, 0, x+1) add(ans, dp[p][0][y]);
    cout << ans << '\n';
    return 0;
}
