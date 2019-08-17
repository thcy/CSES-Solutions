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
    
    constexpr int B=20;
    constexpr int M=1<<B;
    auto rev=[&](int a) {
        return (~a)&(M-1);
    };
    int n;
    cin >> n;
    vi x(n), a(M), b(M);
    rep(i, 0, n) {
        cin >> x[i];
        a[x[i]]++;
        b[rev(x[i])]++;
    }
    rep(j, 0, B) rep(i, 0, M)
    if (i&(1<<j)) {
        a[i]+=a[i^(1<<j)];
        b[i]+=b[i^(1<<j)];
    }
    trav(i, x) {
        cout << a[i] << " " << b[rev(i)] << " ";
        cout << (n-a[rev(i)]) << '\n';
    }
    return 0;
}
