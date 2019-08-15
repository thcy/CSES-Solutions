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
    
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans=0;
    for(int i=0, j=0; i<n && j<m; ) {
        if (abs(a[i]-b[j])<=k)
            ans++, i++, j++;
        else if(a[i]-k>b[j]) j++;
        else i++;
    }
    cout << ans << '\n';
    return 0;
}
