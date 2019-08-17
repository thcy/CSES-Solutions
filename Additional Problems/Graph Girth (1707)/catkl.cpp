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
    vector<vi> g(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=n+1;
    vi d(n+1), p(n+1);
    rep(i, 1, n+1) {
        rep(j, 1, n+1) p[j]=0;
        d[i]=0, p[i]=-1;
        queue<int> q;
        for(q.push(i); !q.empty(); q.pop()) {
            int i=q.front();
            trav(j, g[i]) {
                if (!p[j])
                    d[j]=d[i]+1, p[j]=i, q.push(j);
                else if(p[i]!=j)
                    ans=min(ans, d[i]+d[j]+1);
            }
        }
    }
    cout << (ans>n? -1:ans) << '\n';
    return 0;
}
