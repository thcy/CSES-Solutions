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
    
    int n, m, q;
    cin >> n >> m >> q;
    set<pii> e;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a>b) swap(a, b);
        e.insert({a, b});
    }
    vi L(q), R(q), ans(q);
    rep(i, 0, q) {
        cin >> L[i] >> R[i];
        if (L[i]>R[i]) swap(L[i], R[i]);
        e.erase({L[i], R[i]});
    }
    UF x(n+1);
    int c=n;
    trav(p, e) c-=x.join(p.first, p.second);
    for(int i=q-1; i>=0; i--) {
        ans[i]=c;
        c-=x.join(L[i], R[i]);
    }
    rep(i, 0, q)
    cout << ans[i] << " \n"[i==q-1];
    return 0;
}
