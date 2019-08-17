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
    
    constexpr int P=1e9+7;
    string s;
    cin >> s;
    vi x(26);
    int t=0;
    trav(c, s) {
        int cur=x[c-'a'];
        x[c-'a']=(t+1)%P;
        t=(2LL*t+P+1-cur)%P;
    }
    cout << t << '\n';
    return 0;
}
