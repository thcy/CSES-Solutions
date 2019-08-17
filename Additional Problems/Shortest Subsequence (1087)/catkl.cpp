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
    
    string s,  ans;
    cin >> s;
    set<char> x;
    trav(c, s) {
        x.insert(c);
        if (sz(x)==4)
            ans+=c, x.clear();
    }
    trav(c, string("AGCT"))
    if (!x.count(c)) {
        ans+=c;
        break;
    }
    cout << ans << '\n';
    return 0;
}
