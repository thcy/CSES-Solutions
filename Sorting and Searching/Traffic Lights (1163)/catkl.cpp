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
    
    int x, n;
    cin >> x >> n;
    set<int> p{{0, x}};
    multiset<int> w{{x}};
    vi ans(n);
    rep(i, 0, n) {
        int M;
        cin >> M;
        auto z=p.lower_bound(M);
        int L=*prev(z), R=*z;
        p.insert(M);
        w.erase(w.find(R-L));
        w.insert(M-L);
        w.insert(R-M);
        ans[i]=*w.rbegin();
    }
    rep(i, 0, n)
    cout << ans[i] << " \n"[i==n-1];
    return 0;
}
