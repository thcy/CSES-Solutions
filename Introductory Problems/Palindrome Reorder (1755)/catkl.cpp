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
    
    string s;
    cin >>  s;
    map<char, int> f;
    trav(c, s) f[c]++;
    string ans, odd;
    trav(p, f) {
        ans+=string(p.second/2, p.first);
        if (p.second%2) odd+=p.first;
    }
    if (sz(odd)>1)
        cout << "NO SOLUTION\n";
    else {
        cout << ans + odd;
        reverse(all(ans));
        cout << ans <<'\n';
    }
    return 0;
}
