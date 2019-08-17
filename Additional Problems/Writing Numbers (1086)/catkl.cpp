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
    
    ll n;
    cin >> n;
    auto cnt=[](ll M) {
        ll ans=0, d=1;
        rep(i, 0, 18) {
            ans+=M/(10*d)*d;
            ans+=max(min(M%(10*d)-d, d), 0LL);
            d*=10;
        }
        return ans;
    };
    ll L=1, R=1e18;
    while (L<R) {
        ll M=(L+R)/2;
        if (cnt(M)<=n) L=M+1;
        else R=M;
    }
    cout << L-2 << '\n';
    return 0;
}
