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
    
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    multiset<int> s(all(a));
    int ans=0;
    while (sz(s)) {
        ans++;
        int a=*begin(s);
        s.erase(begin(s));
        auto p=s.upper_bound(x-a);
        if(p!=begin(s))
            s.erase(--p);
    }
    cout << ans << '\n';
    return 0;
}
