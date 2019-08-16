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
    int l, r;
    ll val;
    Node(int l, int r, ll val)
    : l(l), r(r), val(val) {}
};
vector<Node> T;
vi root;

int build(int L, int R, vi &x) {
    if (R-L==1) {
        T.push_back(Node(0, 0, x[L]));
        return sz(T)-1;
    }
    int M=(L+R)/2;
    int ll=build(L, M, x);
    int rr=build(M, R, x);
    T.push_back(Node(ll, rr, T[ll].val+T[rr].val));
    return sz(T)-1;
}

int update(int i, int L, int R, int w, int val) {
    if(R-L==1) {
        T.push_back(Node(0, 0, val));
        return sz(T)-1;
    }
    int M=(L+R)/2;
    int ll=T[i].l, rr=T[i].r;
    if (w<M) ll=update(T[i].l, L, M, w, val);
    else rr=update(T[i].r, M, R, w, val);
    T.push_back(Node(ll, rr, T[ll].val+T[rr].val));
    return sz(T)-1;
}

ll query(int i, int L, int R, int lo, int hi) {
    if (lo<=L && hi>=R)
        return T[i].val;
    if (lo>=R || hi<=L)
        return 0;
    int M=(L+R)/2;
    return query(T[i].l, L, M, lo, hi)
    +query(T[i].r, M, R, lo, hi);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi x(n);
    rep(i, 0, n) cin >> x[i];
    root.push_back(build(0, n, x));
    while (q--) {
        int type, k;
        cin >> type >> k;
        k--;
        if (type==1) {
            int a, b;
            cin >> a >> b;
            root[k]=update(root[k], 0, n, a-1, b);
        }
        else if (type==2) {
            int a, b;
            cin >> a >> b;
            cout << query(root[k], 0, n, a-1, b) << '\n';
        }
        else if (type==3) {
            root.push_back(root[k]);
        }
    }
    return 0;
}
