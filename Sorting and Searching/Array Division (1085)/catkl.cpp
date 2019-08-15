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
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    ll L=*max_element(all(x)), R=L*n;
    while (L<R) {
        ll M=(L+R)/2;
        ll cnt=1, s=0;
        rep(i, 0, n) {
            s+=x[i];
            if (s>M) cnt++, s=x[i];
        }
        if (cnt>k) L=M+1;
        else R=M;
    }
    cout << L << '\n';
    return 0;
}
