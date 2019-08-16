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
    
    int n;
    cin >> n;
    vector<vi> g(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi d(n+1), deg(n+1);
    queue<int> q;
    rep(i, 1, n+1) if ((deg[i]=sz(g[i]))<=1)
        d[i]=1, q.push(i);
    for(; !q.empty(); q.pop())  {
        int i=q.front();
        trav(j, g[i]) if (--deg[j]==1)
            d[j]=d[i]+1, q.push(j);
    }
    int r=*max_element(all(d));
    int c=count(all(d), r);
    cout << 2*(r-1)+(c>1) << '\n';
    return 0;
}
