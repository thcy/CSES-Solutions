#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
    jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
    rep(i,0,sz(tbl))
    if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

vi p, d, c;
void dfs(int i, int t) {
    c[i]=--t;
    int j=p[i];
    if (c[j]==0) dfs(j, t);
    if (c[j]<0)
        c[i]=c[j]-c[i]+1, d[i]=0;
    else
        c[i]=c[j], d[i]=d[j]+1;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    p.resize(n+1);
    d.resize(n+1);
    c.resize(n+1);
    rep(i, 1, n+1) cin >> p[i];
    rep(i, 1, n+1) if(!c[i]) dfs(i, 0);
    vector<vi> tbl=treeJump(p);
    while (q--) {
        int a,  b;
        cin >> a >> b;
        if (d[b]<=d[a] && jmp(tbl, a, d[a]-d[b])==b)
            cout << d[a]-d[b] << '\n';
        else if (d[b]<c[a] && jmp(tbl, a, d[a]+c[a]-d[b])==b)
            cout << d[a]+c[a]-d[b] << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
