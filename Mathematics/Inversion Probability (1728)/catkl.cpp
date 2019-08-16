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
    
    int n;
    cin >> n;
    vi r(n);
    rep(i, 0, n) cin >> r[i];
    double  ans=0;
    rep(i, 0, n) rep(j, i+1, n) {
        if(r[i]<r[j]) ans+=(r[i]-1)*0.5/r[j];
        else ans+=1-(r[j]+1)*0.5/r[i];
    }
    cout << fixed <<setprecision(6);
    cout << ans << '\n';
    return 0;
}
