#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class I> vi lis(vector<I> S) {
    vi prev(sz(S));
    typedef pair<I, int> p;
    vector<p> res;
    rep(i,0,sz(S)) {
        p el { S[i], i };
        //S[i]+1 for non-decreasing
        auto it = lower_bound(all(res), p { S[i]+1, 0 });
        if (it == res.end()) res.push_back(el), it = --res.end();
        *it = el;
        prev[i] = it==res.begin() ?0:(it-1)->second;
    }
    int L = sz(res), cur = res.back().second;
    vi ans(L);
    while (L--) ans[L] = cur, cur = prev[cur];
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    cout << sz(lis(x)) << '\n';
    return 0;
}
