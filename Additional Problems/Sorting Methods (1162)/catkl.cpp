#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    trav(e,g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));
    
    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

template<class I> vi lis(vector<I> S) {
    vi prev(sz(S));
    typedef pair<I, int> p;
    vector<p> res;
    rep(i,0,sz(S)) {
        p el { S[i], i };
        //S[i]+1 for non-decreasing
        auto it = lower_bound(all(res), p { S[i], 0 });
        if (it == res.end()) res.push_back(el), it = --res.end();
        *it = el;
        prev[i] = it==res.begin() ?0:(it-1)->second;
    }
    int L = sz(res), cur = res.back().second;
    vi ans(L);
    while (L--) ans[L] = cur, cur = prev[cur];
    return ans;
}

ll f1(vi &x) {
    int n=sz(x);
    ll ans=0;
    FT t(n);
    rep(i, 0, n) {
        ans+=i-t.query(x[i]-1);
        t.update(x[i]-1, 1);
    }
    return ans;
}

ll f2(vi &x) {
    int n=sz(x);
    vector<vi> g(n);
    rep(i, 0, n) g[i].push_back(x[i]-1);
    scc(g, [](vi&){});
    return n-ncomps;
}

ll f3(vi &x) {
    return sz(x)-sz(lis(x));
}

ll f4(vi &x) {
    int i=0, n=sz(x);
    rep(j, 0, n)
    if (x[n-1-j]==n-i) i++;
    return n-i;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    cout << f1(x) << " " << f2(x) << " " << f3(x) << " " << f4(x) << '\n';
    return 0;
}
