#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> nbs(int i, int j) {
    vector<pii> ans;
    rep(di, -2, 2+1) rep(dj, -2, 2+1) {
        if (di*di+dj*dj!=5) continue;
        int ii=i+di, jj=j+dj;
        if (ii>=0 && ii<8 && jj>=0 && jj<8)
            ans.push_back({ii, jj});
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    vector<vi> x(8, vi(8));
    int i, j;
    cin >> j >> i;
    i--, j--;
    x[i][j]=1;
    rep(k, 2, 65) {
        pii opt{0, 0};
        int val=100;
        trav(p, nbs(i, j)) {
            if (x[p.first][p.second]) continue;
            int cur=0;
            trav(q, nbs(p.first, p.second))
            cur+=(x[q.first][q.second]==0);
            if(cur<val || (cur==val && p.second>opt.first))
                val=cur, opt=p;
        }
        i=opt.first, j=opt.second;
        x[i][j]=k;
    }
    rep(i, 0, 8) rep(j, 0, 8)
    cout << x[i][j] << " \n"[j==7];
    return 0;
}
