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
    vi x(n+1);
    set<pii, greater<pii>> e;
    rep(i, 1, n+1) {
        cin >> x[i];
        if (x[i]<0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (x[i]>0) e.insert({x[i], i});
    }
    vector<pii> ans;
    while (sz(e)) {
        auto p=e.begin();
        int g=p->first, w=p->second;
        vi op;
        rep(i, 0, g) {
            p++;
            if(p==end(e)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            op.push_back(p->second);
        }
        e.erase({x[w], w});
        trav(i, op) {
            ans.push_back({w, i});
            e.erase({x[i], i});
            x[i]--;
            if (x[i]>0) e.insert({x[i], i});
        }
    }
    cout << sz(ans) << '\n';
    trav(p, ans) cout << p.first << " " << p.second << '\n';
    return 0;
}
