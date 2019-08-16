#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll P = 1000000007;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % P, e /= 2)
        if (e & 1) ans = ans * b % P;
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    string s;
    cin >> s;
    int n=sz(s);
    vector<ll> f(n+1), invf(n+1);
    f[0]=1;
    rep(i, 1, n+1)
    f[i]=f[i-1]*i%P;
    invf[n]=modpow(f[n], P-2);
    for(int i=n; i; i--)
        invf[i-1]=invf[i]*i%P;
    vi cnt(26);
    trav(c, s) cnt[c-'a']++;
    ll ans=f[n];
    trav(i, cnt)
    ans=ans*invf[i]%P;
    cout << ans << '\n';
    return 0;
}
