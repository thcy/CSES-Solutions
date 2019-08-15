#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string f, dl="UDLR";
char x[9][9];
vi di{-1, 1, 0, 0}, dj{0, 0, -1, 1};
int ans;

void dfs(int i, int j, int w) {
    if (!f[w]) {
        ans++;
        return;
    }
    if (i==7 && j==1) return;
    if (x[i-1][j] && x[i+1][j] && !x[i][j-1] && !x[i][j+1]) return;
    if (!x[i-1][j] && !x[i+1][j] && x[i][j-1] && x[i][j+1])    return;
    x[i][j]=1;
    rep(d, 0, 4) {
        int ii=i+di[d];
        int jj=j+dj[d];
        if(x[ii][jj]) continue;
        if (f[w]!='?' && f[w]!=dl[d]) continue;
        dfs(ii, jj, w+1);
    }
    x[i][j]=0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    rep(i, 1, 8) {
        x[i][0]=x[i][8]=1;
        x[0][i]=x[8][i]=1;
    }
    cin >> f;
    dfs(1, 1, 0);
    cout << ans << '\n';
    return 0;
}
