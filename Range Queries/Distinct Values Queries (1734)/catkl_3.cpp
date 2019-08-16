#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int B=450;
struct Q {
    int L, R, cmp, id;
    bool operator<(const Q &o) const {
        return cmp<o.cmp;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, nq;
    cin >> n >> nq;
    map<int, vi> f;
    rep(i, 0, n) {
        int a;
        cin >> a;
        f[a].push_back(i);
    }
    vi x(n);
    int k=0;
    trav(p, f) {
        trav(i, p.second) x[i]=k;
        k++;
    }
    vi cnt(k);
    vector<Q> q(nq);
    rep(i, 0, nq) {
        cin >> q[i].L >> q[i].R;
        q[i].L--, q[i].R--;
        q[i].cmp=(q[i].L/B)*n+q[i].R;
        q[i].id=i;
    }
    sort(all(q));
    int L=0, R=-1, dc=0;
    vi qans(nq);
    trav(cq, q) {
        while (L<cq.L) if (--cnt[x[L++]]==0) dc--;
        while (L>cq.L) if (++cnt[x[--L]]==1) dc++;
        while (R<cq.R) if (++cnt[x[++R]]==1) dc++;
        while (R>cq.R) if (--cnt[x[R--]]==0) dc--;
        qans[cq.id]=dc;
    }
    trav(i, qans) cout << i << '\n';
    return 0;
}
