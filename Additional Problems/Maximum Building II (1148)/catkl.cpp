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
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vi z(m+2), f(m+2);
    vector<vi> ans(n+2, vi(m+2));
    rep(r, 0, n) {
        rep(c, 1, m+1)
        z[c]=(s[r][c-1]=='*'? 0:z[c]+1);
        vi h(z);
        set<pii, greater<pii>> y;
        rep(c, 0, m+2) {
            int d;
            for(d=c; d<m+1; d++)
                if (h[d+1]!=h[c]) break;
            f[c]=d, f[d]=c;
            y.insert({h[c], c});
            c=d;
        }
        int L, R, H, NH;
        while ((H=h[L=begin(y)->second])) {
            R=f[L];
            NH=max(h[L-1], h[R+1]);
            ans[NH+1][R-L+1]++;
            ans[H+1][R-L+1]--;
            y.erase(begin(y));
            if(h[L-1]==NH)
                L=f[L-1], y.erase({h[L], L});
            if(h[R+1]==NH)
                y.erase({h[R+1], R+1}), R=f[R+1];
            f[L]=R, f[R]=L;
            y.insert({h[L]=h[R]=NH, L});
        }
    }
    rep(r, 1, n+1) rep(c, 1, m+1)
    ans[r][c]+=ans[r-1][c];
    rep(r, 1, n+1) {
        rep(k, 0, 2) for (int c=m; c; c--)
            ans[r][c]+=ans[r][c+1];
        rep(c, 1, m+1) cout << ans[r][c] << " \n"[c==m];
    }
    return 0;
}
