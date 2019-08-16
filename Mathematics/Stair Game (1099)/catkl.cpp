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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int r=0;
        rep(i, 0, n) {
            int x;
            cin >> x;
            if (i%2) r^=x;
        }
        cout << (r? "first" : "second") << '\n';
    }
    return 0;
}
