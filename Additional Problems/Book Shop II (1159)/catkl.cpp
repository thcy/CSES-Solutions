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
    
    int n, x;
    cin >> n >> x;
    vi h(n), s(n), c(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> c[i];
    vi dp(x+1);
    vector<pii> q(x+1);
    rep(i, 0, n) rep(j, 0, min(x+1, h[i])) {
        int L=0, R=0;
        for(int k=j, u=0; k<=x; k+=h[i], u++) {
            pii p(dp[k]-u*s[i], u);
            while(R>L && q[R-1]<p) R--;
            q[R++]=p;
            if(q[L].second==u-c[i]-1) L++;
            dp[k]=q[L].first+u*s[i];
        }
    }
    cout << *max_element(all(dp)) << '\n';
    return 0;
}
