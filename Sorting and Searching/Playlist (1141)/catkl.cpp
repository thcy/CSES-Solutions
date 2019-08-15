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
    
    int n, b=0, ans=0;
    cin >> n;
    map<int, int> last;
    rep(i, 1, n+1) {
        int a;
        cin >> a;
        b=max(b, last[a]);
        ans=max(ans, i-b);
        last[a]=i;
    }
    cout << ans << '\n';
    return 0;
}
