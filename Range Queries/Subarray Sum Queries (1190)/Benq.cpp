#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

class node {
public:
    ll mxSum = 0, mnSum = 0, sum = 0, ans = 0;
    node(ll _sum) {
        sum = _sum;
        mxSum = ans = max(sum,0LL);
        mnSum = min(sum,0LL);
    }
    node() {
        node(0);
    }
};

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = node(0);
    
    Seg() {
        F0R(i,2*SZ) seg[i] = node();
    }
    
    T comb(T a, T b) {
        node c = node(0);
        c.mxSum = max(a.mxSum,a.sum+b.mxSum);
        c.mnSum = min(a.mnSum,a.sum+b.mnSum);
        c.sum = a.sum+b.sum;
        c.ans = max(max(a.ans,b.ans),a.sum-a.mnSum+b.mxSum);
        return c;
    }
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = node(value); p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
        
        
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

Seg<node,1<<18> S;
int n,m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) {
        int x; cin >> x;
        S.upd(i,x);
    }
    F0R(i,m) {
        int k,x; cin >> k >> x;
        S.upd(k-1,x);
        cout << S.seg[1].ans << "\n";
    }
}
