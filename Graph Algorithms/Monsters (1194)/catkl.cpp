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
    
    constexpr int inf=1e9;
    int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
    char dl[]="UDLR";
    int R, C;
    cin >> R >> C;
    vector<string> s(R);
    queue<pii> q;
    vector<vi> mt(R, vi(C, inf)), ht(R, vi(C, inf)), p(R, vi(C));
    int r0=0, c0=0;
    rep(r, 0, R) {
        cin >> s[r];
        rep(c, 0, C) {
            if (s[r][c]=='A')
                ht[r][c]=0, r0=r, c0=c, s[r][c]='.';
            if (s[r][c]=='M')
                mt[r][c]=0, q.push({r,c}), s[r][c]='.';
        }
    }
    for (; !q.empty(); q.pop()) {
        int r, c;
        tie(r, c)=q.front();
        rep(d, 0, 4) {
            int rr=r+dr[d];
            int cc=c+dc[d];
            if (rr<0 || rr>=R || cc<0 || cc>=C)
                continue;
            if (s[rr][cc]=='.' && mt[rr][cc]==inf)
                mt[rr][cc]=mt[r][c]+1, q.push({rr, cc});
        }
    }
    for (q.push({r0, c0}); !q.empty(); q.pop()) {
        int r, c;
        tie(r, c)=q.front();
        rep(d, 0, 4) {
            int rr=r+dr[d];
            int cc=c+dc[d];
            if (rr<0 || rr>=R || cc<0 || cc>=C)
                continue;
            if (s[rr][cc]=='.' && ht[rr][cc]==inf
                && ht[r][c]+1<mt[rr][cc]) {
                ht[rr][cc]=ht[r][c]+1;
                q.push({rr, cc});
                p[rr][cc]=d;
            }
        }
    }
    rep(r, 0, R) rep(c, 0, C) {
        if (r>0 && r<R-1 && c>0 && c<C-1) continue;
        if (ht[r][c]<inf) {
            string ans;
            while (r!=r0 || c!=c0) {
                int d=p[r][c];
                ans+=dl[d];
                r-=dr[d], c-=dc[d];
            }
            reverse(all(ans));
            cout << "YES\n" << sz(ans) << '\n' << ans << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
