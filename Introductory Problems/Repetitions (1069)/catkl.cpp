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
    cin >> s;
    int ans=1, r=1;
    rep(i, 1, sz(s)) {
        if (s[i]==s[i-1]) r++;
        else r=1;
        ans=max(ans, r);
    }
    cout << ans << '\n';
    return 0;
}
