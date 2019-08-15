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
};

Seg<ll,1<<19> S;
int n;
vector<array<int,3>> v;
map<int,int> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        int a,b,p; cin >> a >> b >> p;
        m[a] = m[b+1] = 0;
        v.pb({a,b,p});
    }
    int nex = 0;
    for (auto& a: m) a.s = nex++;
    sort(v.rbegin(),v.rend());
    for (auto& a: v) {
        a[0] = m[a[0]];
        a[1] = m[a[1]+1];
        ll x = S.query(a[1],(1<<19)-1)+a[2];
        if (x > S.query(a[0],a[0])) S.upd(a[0],x);
    }
    cout << S.query(0,(1<<19)-1);
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
