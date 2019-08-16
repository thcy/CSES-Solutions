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
    
    constexpr int M=1000000;
    vi c(M+1);
    int n;
    cin >> n;
    rep(i, 0, n) {
        int x;
        cin >> x;
        c[x]++;
    }
    int ans=1;
    rep(i, 2, M+1) {
        int cnt=0;
        for(int j=i; j<=M; j+=i)
            cnt+=c[j];
        if (cnt>=2) ans=i;
    }
    cout << ans << '\n';
    return 0;
}
