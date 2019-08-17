#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int nl;
vector<vi> g, a;
vi sl;

int dfs1(int i, int p) {
    int r, ml=0;
    trav(j, g[i]) if (j!=p) {
        if ((r=dfs1(j, i))) return r;
        sl[i]+=sl[j];
        ml=max(ml, sl[j]);
    }
    ml=max(ml, nl-sl[i]);
    return (sz(g[i])>1 && 2*ml<=nl? i:0);
}

void dfs2(int i, int p) {
    trav(j, g[i]) if(j!=p)
        dfs2(j, i);
    if (sz(g[i])==1)
        a.back().push_back(i);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    g.resize(n+1);
    sl.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, 1, n+1) if (sz(g[i])==1)
        sl[i]=1, nl++;
    int r=dfs1(1, 0);
    trav(i, g[r]) {
        a.push_back({});
        dfs2(i, r);
    }
    if (nl%2) {
        int i=0;
        rep(j, 0, sz(a))
        if(sz(a[j])<sz(a[i])) i=j;
        a[i].push_back(a[i].back());
        
    }
    set<pii, greater<pii>> x;
    rep(i, 0, sz(a))
    x.insert({sz(a[i]), i});
    cout << (nl+1)/2 << '\n';
    while (sz(x)) {
        int s1, s2, i1, i2;
        tie(s1, i1)=*begin(x);
        x.erase(begin(x));
        tie(s2, i2)=*begin(x);
        x.erase(begin(x));
        cout << a[i1].back() << " " << a[i2].back() << '\n';
        a[i1].pop_back();
        a[i2].pop_back();
        if (s1>1) x.insert({s1-1, i1});
        if (s2>1) x.insert({s2-1, i2});
    }
    return 0;
}
