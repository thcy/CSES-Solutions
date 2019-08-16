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
    vector<vi> ht(R, vi(C, inf)), p(R, vi(C));
    int r0=0, c0=0, r1=0, c1=0;
    rep(r, 0, R) {
        cin >> s[r];
        rep(c, 0, C) {
            if (s[r][c]=='A')
                ht[r][c]=0, r0=r, c0=c, s[r][c]='.';
            if (s[r][c]=='B')
                r1=r, c1=c, s[r][c]='.';
        }
    }
    for (q.push({r0, c0}); !q.empty(); q.pop()) {
        int r, c;
        tie(r, c)=q.front();
        if (r==r1 && c==c1) break;
        rep(d, 0, 4) {
            int rr=r+dr[d];
            int cc=c+dc[d];
            if (rr<0 || rr>=R || cc<0 || cc>=C)
                continue;
            if (s[rr][cc]=='.' && ht[rr][cc]==inf) {
                ht[rr][cc]=ht[r][c]+1;
                q.push({rr, cc});
                p[rr][cc]=d;
            }
        }
    }
    if (ht[r1][c1]==inf)
        cout << "NO\n";
    else {
        string ans;
        int r=r1, c=c1;
        do {
            int d=p[r][c];
            ans+=dl[d];
            r-=dr[d], c-=dc[d];
        } while (r!=r0 || c!=c0);
        reverse(all(ans));
        cout << "YES\n" << sz(ans) << '\n' << ans << '\n';
    }
    return 0;
}
