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
    
    int R, C;
    cin >> R >> C;
    vector<string> f(R);
    rep(r, 0, R) cin >> f[r];
    int ans=0;
    queue<pii> q;
    vi dr{0, 0, -1, 1}, dc{-1, 1, 0, 0};
    rep(r, 0, R) rep(c, 0, C) if (f[r][c]=='.') {
        ans++;
        f[r][c]='#';
        for (q.push({r, c}); !q.empty(); q.pop()) {
            int i=q.front().first;
            int j=q.front().second;
            rep(d, 0, 4) {
                int ii=i+dr[d], jj=j+dc[d];
                if (ii<0 || ii==R || jj<0 || jj==C)
                    continue;
                if (f[ii][jj]=='.')
                    f[ii][jj]='#', q.push({ii, jj});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
