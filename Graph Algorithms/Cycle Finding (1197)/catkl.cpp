#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = LLONG_MAX;
struct Ed { int a, b, w, s() { return a < b ? a : -a; }};
struct Node { ll dist = inf; int prev = -1; };

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
    nodes[s].dist = 0;
    sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });
    
    int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
    rep(i,0,lim) trav(ed, eds) {
        Node cur = nodes[ed.a], &dest = nodes[ed.b];
        if (abs(cur.dist) == inf) continue;
        ll d = cur.dist + ed.w;
        if (d < dest.dist) {
            dest.prev = ed.a;
            dest.dist = (i < lim-1 ? d : -inf);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<Node> v(n+1);
    vector<Ed> e(m+n);
    rep(i, 0, m)
    cin >> e[i].a >> e[i].b >> e[i].w;
    rep(i, m, m+n)
    e[i].a=e[i].w=0,  e[i].b=i-m+1;
    bellmanFord(v, e, 0);
    rep(i, 1, n+1) if(v[i].dist==-inf) {
        cout << "YES\n";
        vi p(1), u(n+1);
        do {
            u[i]=sz(p);
            p.push_back(i);
            i=v[i].prev;
        } while(!u[i]);
        vi ans(begin(p)+u[i], end(p));
        reverse(all(ans));
        trav(i, ans) cout << i << " ";
        cout << ans[0] << '\n';
        return 0;
    }
    cout << "NO\n";
    return 0;
}
