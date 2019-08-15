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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, pii> R;
    rep(i, 0, n) rep(j, i+1, n)
    R[a[i]+a[j]]={i, j};
    rep(i, 0, n) rep(j, i+1, n) {
        int y=x-a[i]-a[j];
        if (y>0 && R.count(y) && R[y].first>j) {
            cout << i+1 << " " << j+1 << " ";
            cout << R[y].first+1 << " " << R[y].second+1 << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
