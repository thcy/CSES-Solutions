#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void outp(vector<pii> &r) {
    cout << sz(r) << '\n';
    trav(p, r)
    cout << p.first << " " << p.second << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vi x(n+1);
    rep(i, 1, n+1) cin >> x[i];
    vector<vi> c;
    int mc=0;
    rep(i, 1, n+1) if (x[i]) {
        vi cur;
        int j=i;
        do {
            cur.push_back(j);
            j=x[j];
        } while (j!=i);
        trav(j, cur) x[j]=0;
        c.push_back(cur);
        mc=max(mc, sz(cur));
    }
    if (mc==1) {
        cout << "0\n";
    }
    else if (mc==2) {
        vector<pii> r;
        cout << "1\n";
        trav(p, c) if (sz(p)==2)
            r.push_back({p[0], p[1]});
        outp(r);
    }
    else {
        cout << "2\n";
        vector<pii> r;
        trav(p, c) {
            int m=sz(p);
            if (m==2)
                r.push_back({p[0], p[1]});
            if (m>2) {
                rep(i, 0, m) if (i<(m-i)%m)
                    r.push_back({p[i], p[(m-i)%m]});
            }
        }
        outp(r);
        r.clear();
        trav(p, c) {
            int m=sz(p);
            if (m>2) {
                rep(i, 0, m) if (i<(m+1-i)%m)
                    r.push_back({p[i], p[(m+1-i)%m]});
            }
        }
        outp(r);
    }
    return 0;
}
