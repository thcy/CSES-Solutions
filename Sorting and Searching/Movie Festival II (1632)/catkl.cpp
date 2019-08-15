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
    
    int n, k;
    cin >> n >> k;
    vector<pii> e(n);
    rep(i, 0, n) cin >> e[i].first >> e[i].second;
    sort(all(e));
    multiset<int> q;
    int ans=0;
    trav(p, e) {
        while (!q.empty() && *begin(q)<=p.first)
            q.erase(begin(q));
        if (sz(q)<k)
            ans++, q.insert(p.second);
        else if (*q.rbegin()>p.second) {
            q.erase(--end(q));
            q.insert(p.second);
        }
    }
    cout << ans << '\n';
    return 0;
}
