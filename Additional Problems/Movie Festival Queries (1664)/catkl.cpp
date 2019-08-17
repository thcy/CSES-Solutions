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
    
    constexpr int inf=1e9;
    constexpr int B=20;
    int n, q;
    cin >> n >> q;
    vector<pii> x(n);
    rep(i, 0, n) cin >> x[i].first >> x[i].second;
    sort(all(x));
    x.push_back({inf, inf});
    vector<pii> y(x);
    y.back().second=n;
    int cur=n;
    for (int i=n-1; i>=0; i--) {
        if (x[i].second<=x[cur].second)
            cur=i;
        y[i].second=cur;
    }
    auto nxt=[&](int t) {
        return lower_bound(all(y), pii{t, 0})->second;
    };
    vector<vi> t(n+1, vi(B));
    rep(i, 0, n+1)
    t[i][0]=nxt(x[i].second);
    rep(b, 1, B) rep(i, 0, n+1)
    t[i][b]=t[t[i][b-1]][b-1];
    while (q--) {
        int L, R;
        cin >> L >> R;
        int i=nxt(L), ans=(x[i].second<=R);
        for (int b=B-1; b>=0; b--) {
            if (x[t[i][b]].second<=R)
                i=t[i][b], ans+=1<<b;
        }
        cout << ans << '\n';
    }
    return 0;
}
