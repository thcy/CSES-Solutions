#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, madd = 0, val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of 0
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
            madd += x;
        else
            push(), l->add(L, R, x), r->add(L, R, x);
        if (madd) val=hi-lo;
        else val=(l? l->val:0)+(r? r->val:0);
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    map<int, vector<array<int, 3>>> e;
    rep(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e[x1].push_back({y1, y2, 1});
        e[x2].push_back({y1, y2, -1});
    }
    Node *tr = new Node(-inf, inf);
    ll x=-inf, ans=0;
    trav(a, e) trav(p, a.second) {
        ans+=(a.first-x)*tr->val;
        tr->add(p[0], p[1], p[2]);
        x=a.first;
    }
    cout << ans << '\n';
    return 0;
}
