#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool same_set(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    UF dsu(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        dsu.join(a-1, b-1);
    }
    map<int, int> cnt;
    trav(a, dsu.e)
    if (a<0) cnt[-a]++;
    vi dp(n+1), s(n+1);
    dp[0]=1;
    trav(a, cnt) {
        int x=a.first, m=a.second+1;
        rep(i, 0, n+1) {
            s[i]=dp[i];
            if (i>=x) s[i]+=s[i-x];
            dp[i]=(s[i] > (i>=m*x? s[i-m*x]:0));
        }
    }
    rep(i, 1, n+1)
    cout << dp[i];
    cout << '\n';
    return 0;
}
