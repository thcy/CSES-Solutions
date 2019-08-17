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
    int n=sz(s);
    vector<pii> x(n);
    rep(i, 0, n) x[i]={s[i], i};
    sort(all(x));
    string ans;
    int j=0;
    rep(i, 0, n) {
        ans+=x[j].first;
        j=x[j].second;
    }
    cout << ans.substr(1) << '\n';
    return 0;
}
