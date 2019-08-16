#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
    typedef ll T;
    static constexpr T unit = 0;
    static constexpr T none = 1e18;
    T f(T a, T b) { return a+b; }
    T fset(T a) {
        return type? 1LL*(hi-lo)*(hi-1+lo)/2*a : (hi-lo)*a;
    }
    T fadd(T a) {
        return val+(type? 1LL*(hi-lo)*(hi-1+lo)/2*a : (hi-lo)*a);
    }
    Node *l = 0, *r = 0;
    int lo, hi, type;
    T mset = none, madd = unit, val = unit;
    Node(int lo, int hi, int type)
    :lo(lo), hi(hi), type(type) {}
    Node(vector<T>& v, int lo, int hi, int type)
    : lo(lo), hi(hi), type(type) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid, type);
            r = new Node(v, mid, hi, type);
            val = f(l->val, r->val);
        }
        else val = fset(v[lo]);
    }
    T query(int L, int R) {
        if (R <= lo || hi <= L) return unit;
        if (L <= lo && hi <= R) return val;
        push();
        return f(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
            mset = x, madd = unit, val = fset(x);
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = f(l->val, r->val);
        }
    }
    void add(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != none) mset = f(mset, x);
            else madd = f(madd, x);
            val = fadd(x);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = f(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid, type); r = new Node(mid, hi, type);
        }
        if (mset != none)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = none;
        else if (madd!=unit)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = unit;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vector<ll> v0(n+1), v1(n+1);
    rep(i, 1, n+1) cin >> v0[i];
    Node* tr0 = new Node(v0, 0, n+1, 0);
    Node* tr1 = new Node(v1, 0, n+1, 1);
    while (q--)  {
        int type, L, R;
        cin >> type >> L >> R;
        if (type==1) {
            tr0->add(L, R+1, -L+1);
            tr1->add(L, R+1, 1);
        }
        else
            cout << tr0->query(L, R+1) + tr1->query(L, R+1) << '\n';
    }
    return 0;
}
