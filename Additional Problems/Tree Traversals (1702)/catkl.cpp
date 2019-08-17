#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi po, io, ans;

void solve(int L, int R, int l, int r) {
    if (L==R) return;
    int s=io[po[L]]-l;
    solve(L+1, L+s+1, l, l+s);
    solve(L+s+1, R, l+s+1, r);
    ans.push_back(po[L]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    po.resize(n+1);
    io.resize(n+1);
    rep(i, 0, n) cin >> po[i];
    rep(i, 0, n) {
        int a;
        cin >> a;
        io[a]=i;
    }
    solve(0, n, 0, n);
    rep(i, 0, n)
    cout << ans[i] << " \n"[i==n-1];
    return 0;
}
