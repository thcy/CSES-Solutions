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
    
    constexpr int B=20;
    ll n, k;
    cin >> n >> k;
    vector<ll> x(2*n);
    rep(i, 0, n) {
        cin >> x[i];
        x[i+n]=x[i];
    }
    if (accumulate(all(x), 0LL)<=2*k) {
        cout << "1\n";
        return 0;
    }
    vector<vector<ll>> p(n, vector<ll>(B));
    ll j=0, s=0;
    rep(i, 0, n) {
        while (s<=k) s+=x[j++];
        p[i][0]=j-i-1;
        s-=x[i];
    }
    rep(b, 1, B) rep(i, 0, n) {
        ll d=p[i][b-1];
        p[i][b]=d+p[(i+d)%n][b-1];
    }
    ll ans=n;
    rep(i, 0, n) {
        ll j=0, s=0;
        for(int b=B-1; b>=0; b--)
            if (s+p[(i+s)%n][b]<n)
                s+=p[(i+s)%n][b], j+=1<<b;
        ans=min(ans, j+1);
    }
    cout << ans << '\n';
    return 0;
}
