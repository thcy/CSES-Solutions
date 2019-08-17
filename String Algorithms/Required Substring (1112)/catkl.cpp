#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int P=1e9+7;

vi pi(const string& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

void add(int &x, int y) {
    x+=y;
    if (x>=P) x-=P;
}

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % P, e /= 2)
        if (e & 1) ans = ans * b % P;
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int A=26;
    int n;
    string s;
    cin >> n >> s;
    int m=sz(s);
    vi p=pi(s);
    vector<vi> T(m, vi(A));
    rep(i, 0, m) T[i][s[0]-'A']=1;
    rep(i, 1, m) {
        for(int j=i; j>0; j=p[j-1]) {
            int &t=T[i][s[j]-'A'];
            t=max(t, j+1);
        }
    }
    vector<vi> dp(n+1, vi(m+1));
    dp[0][0]=1;
    rep(i, 0, n) rep(j, 0, m) rep(k, 0, A)
    add(dp[i+1][T[j][k]], dp[i][j]);
    int ans=0;
    rep(i, 0, m) add(ans, dp[n][i]);
    cout << (modpow(A, n)+P-ans)%P << '\n';
    return 0;
}
