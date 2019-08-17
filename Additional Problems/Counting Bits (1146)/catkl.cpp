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
    
    constexpr int B=60;
    ll n, ans=0;
    cin >> n;
    n++;
    rep(b, 0, B) {
        ans+=(n>>(b+1))<<b;
        ans+=min(n%(1LL<<(b+1)), 1LL<<b);
    }
    cout << n*B-ans << '\n';
    return 0;
}
