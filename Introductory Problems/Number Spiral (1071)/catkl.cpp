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
    
    ll t;
    cin >> t;
    while (t--) {
        ll r, c, ans;
        cin >> r >> c;
        ll d=max(r-1, c-1);
        if (d%2==0) {
            if(r==d+1) ans=d*d+c;
            else ans=(d+1)*(d+1)-r+1;
        }
        else {
            if (c==d+1) ans=d*d+r;
            else ans=(d+1)*(d+1)-c+1;
        }
        cout << ans << '\n';
    }
    return 0;
}
