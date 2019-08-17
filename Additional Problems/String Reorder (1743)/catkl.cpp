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
    vi f(26);
    trav(c, s) f[c-'A']++;
    string ans;
    int n=sz(s), last=-1;
    rep(i, 0, n) {
        int j=-1, k=0;
        rep(c, 0, 26) {
            if (j==-1 && f[c] && c!=last) j=c;
            if (f[c]>f[k]) k=c;
        }
        if (j==-1) {
            cout << "-1\n";
            return 0;
        }
        last=(k==last || 2*f[k]-1<n-i? j:k);
        ans+='A'+last;
        f[last]--;
    }
    cout << ans << '\n';
    return 0;
}
