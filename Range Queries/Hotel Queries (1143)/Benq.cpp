#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = 0;
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return max(a,b); } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1){
            //be careful here: some updates are noncommutative!
            if (p < (p^1)){
                seg[p>>1] = comb(seg[p],seg[p^1]);
            }
            else{
                seg[p>>1] = comb(seg[p^1], seg[p]);
            }
        }
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = comb(res,seg[l++]);
            if (r&1) res = comb(res,seg[--r]);
        }
        return res;
    }
    
    int get(int x) {
        if (seg[1] < x) return 0;
        int ind = 1, lo = 0, hi = SZ-1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (seg[2*ind] >= x) {
                hi = mid;
                ind *= 2;
            } else {
                lo = mid+1;
                ind = 2*ind+1;
            }
        }
        return lo;
    }
};

Seg<int,1<<18> S;
int n,m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) {
        int x; cin >> x;
        S.upd(i+1,x);
    }
    F0R(i,m) {
        int x; cin >> x;
        int X = S.get(x);
        if (X == 0) cout << "0 ";
        else {
            S.upd(X,S.query(X,X)-x);
            cout << X << " ";
        }
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
