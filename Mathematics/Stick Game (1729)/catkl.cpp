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
    vi p(k);
    rep(i, 0, k) cin >> p[i];
    string s(n+1, 'L');
    rep(i, 1, n+1) trav(j, p)
    if (i>=j && s[i-j]=='L') {
        s[i]='W';
        break;
    }
    cout << s.substr(1) <<'\n';
    return 0;
}
