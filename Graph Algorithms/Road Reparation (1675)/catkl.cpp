#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool same_set(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, a, b});
    }
    sort(all(e));
    ll nc=n, s=0;
    UF uf(n+1);
    trav(p, e) {
        int a, b, c;
        tie(c, a, b)=p;
        if(uf.join(a, b))
            nc--, s+=c;
    }
    if (nc>1) cout << "IMPOSSIBLE\n";
    else cout << s << '\n';
    return 0;
}
