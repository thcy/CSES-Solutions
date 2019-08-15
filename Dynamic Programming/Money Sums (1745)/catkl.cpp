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
    
    const int N=100*1000+1;
    bitset<N> dp(1);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        dp|=dp<<x;
    }
    cout << dp.count()-1 << '\n';
    int first=1;
    rep(i, 1, N+1) if (dp[i]) {
        if (!first) cout << ' ';
        first=0;
        cout << i;
    }
    cout << '\n';
    return 0;
}
