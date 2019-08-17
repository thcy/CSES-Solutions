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
    
    int x, n;
    cin >> x >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    while (n--) {
        ll a;
        cin >> a;
        q.push(a);
    }
    ll ans=0;
    while (sz(q)>=2) {
        ll a=q.top(); q.pop();
        ll b=q.top(); q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    cout << ans << '\n';
    return 0;
}
