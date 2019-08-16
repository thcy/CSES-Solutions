#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi s;
vector<vi> g;

void dfs(int i, int p) {
    s[i]++;
    trav(j, g[i]) if (j!=p) {
        dfs(j, i);
        s[i]+=s[j];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    g.resize(n+1);
    s.resize(n+1);
    rep(i, 2, n+1) {
        int a;
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    dfs(1, 0);
    rep(i, 1, n+1)
    cout << s[i]-1 << " \n"[i==n];
    return 0;
}
