#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int n, d;
vector<vi> g, dp, dpw;
vi t, e, ew, ans;

void dfsSmall(int i, int p) {
    trav(j, g[i]) if (j!=p)
        dfsSmall(j, i);
    rep(k, 0, d) t[k]=0;
    trav(j, g[i]) if (j!=p) rep(k, 0, d)
        t[k]+=dp[j][k];
    dp[i][0]=1+t[d-1];
    trav(j, g[i]) if (j!=p) rep(k, 0, d-1) {
        int c=max(k, d-k-2);
        dp[i][k+1]=max(dp[i][k+1],
                       dp[j][k]+t[c]-dp[j][c]);
    }
    for(int k=d-1; k>0; k--)
        dp[i][k-1]=max(dp[i][k-1], dp[i][k]);
}

void recSmall(int i, int p, int f) {
    rep(k, 0, d) t[k]=0;
    trav(j, g[i]) if (j!=p) rep(k, 0, d)
        t[k]+=dp[j][k];
    int s=0, ds=0, dc=d-1;
    if (f==0 && dp[i][0]==1+t[d-1])
        ans.push_back(i);
    else {
        trav(j, g[i]) if (j!=p) rep(k, max(f-1, 0), d-1) {
            int c=max(k, d-k-2);
            if (dp[i][f]==dp[j][k]+t[c]-dp[j][c]) {
                s=j, ds=k, dc=c;
                goto out1;
            }
        }
    }
out1:
    trav(j, g[i]) if (j!=p)
        recSmall(j, i, (j==s? ds:dc));
}

void solveSmall() {
    dp.assign(n+1, vi(d));
    t.resize(d);
    dfsSmall(1, 0);
    recSmall(1, 0, 0);
}

void dfsLarge(int i, int p) {
    trav(j, g[i]) if (j!=p)
        dfsLarge(j, i);
    t.clear();
    trav(j, g[i]) if (j!=p)
        t.insert(end(t), all(dp[j]));
    sort(all(t));
    e.assign(sz(t)+3, -1);
    ew.assign(sz(t)+3, -1);
    auto tail=[&](int k, vi& a) {
        return end(a)-lower_bound(all(a), k);
    };
    e[1+tail(d-1, t)]=0;
    ew[1+tail(d-1, t)]=-1;
    trav(j, g[i]) if (j!=p) rep(k, 0, sz(dp[j])) {
        int c=max(dp[j][k], d-dp[j][k]-2);
        int x=sz(dp[j])-k + tail(c, t)-tail(c, dp[j]);
        if (e[x]<dp[j][k]+1)
            e[x]=dp[j][k]+1, ew[x]=j+(n+1)*k;
        if (2*dp[j][k]+2>=d) break;
    }
    int m=sz(e)-2;
    while(e[m]<0) m--;
    dp[i].reserve(m);
    dpw[i].reserve(m);
    for(int k=m; k>0; k--) {
        if (e[k]<e[k+1])
            e[k]=e[k+1], ew[k]=ew[k+1];
        if (e[k]>=0) {
            dp[i].push_back(e[k]);
            dpw[i].push_back(ew[k]);
        }
    }
}

void recLarge(int i, int p, int f) {
    int k=lower_bound(all(dp[i]), f)-begin(dp[i]);
    if (k==sz(dp[i])) return;
    int s=0, ds=0, dc=d-1, val=dpw[i][k];
    if (val==-1)
        ans.push_back(i);
    else {
        s=val%(n+1);
        ds=dp[s][val/(n+1)];
        dc=max(ds, d-ds-2);
    }
    trav(j, g[i]) if (j!=p)
        recLarge(j, i, (j==s? ds:dc));
}

void solveLarge() {
    dp.assign(n+1, vi());
    dpw.assign(n+1, vi());
    e.reserve(n);
    dfsLarge(1, 0);
    recLarge(1, 0, 0);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int D=400;
    cin >> n >> d;
    g.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (d<D) solveSmall();
    else solveLarge();
    cout << sz(ans) << '\n';
    rep(i, 0, sz(ans))
    cout << ans[i] << " \n"[i==sz(ans)-1];
    return 0;
}
