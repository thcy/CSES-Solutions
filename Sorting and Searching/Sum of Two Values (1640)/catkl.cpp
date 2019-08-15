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
    map<int, int> f;
    rep(i, 1, n+1) {
        int a;
        cin >> a;
        if (f.count(x-a)) {
            cout << f[x-a] << " " << i << '\n';
            return 0;
        }
        f[a]=i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
