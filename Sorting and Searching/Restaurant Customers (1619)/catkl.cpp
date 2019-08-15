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
    map<int, int> t;
    while (n--) {
        int a, b;
        cin >> a >> b;
        t[a]++, t[b]--;
    }
    int cur=0, ans=0;
    trav(p, t)
    cur+=p.second, ans=max(ans, cur);
    cout << ans << '\n';
    return 0;
}
