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

typedef pair<ll,ll> pll;

const ll INF = 1e18;

Tree<pii> T;
int n,k, hei[200000];
array<ll,3> ans = {INF,INF,INF};

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] = {bit[k].f+val.f,bit[k].s+val.s};
    }
    
    T query(int k) {
        T temp = {0,0};
        for (;k > 0;k -= (k&-k)) temp = {temp.f+bit[k].f,temp.s+bit[k].s};
        return temp;
    }
    T query(int l, int r) {
        T a = query(r);
        T b = query(l-1);
        return {a.f-b.f,a.s-b.s};
    } // range query [l,r]
};

BIT<pll,200001> B;
map<int,int> m;
vi rm;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    F0R(i,n) {
        cin >> hei[i];
        m[hei[i]] = 0;
    }
    for (auto& a: m) {
        rm.pb(a.f);
        a.s = sz(rm);
    }
    
    int hi = -1;
    F0R(i,n-k+1) {
        while (hi < i+k-1) {
            hi ++;
            T.insert({hei[hi],hi});
            B.upd(m[hei[hi]],{hei[hi],1});
        }
        int med = T.find_by_order(k/2)->f;
        
        pll p1 = B.query(1,m[med]-1), p2 = B.query(m[med]+1,200000);
        cout << p1.s*med-p1.f+p2.f-p2.s*med << " ";
        
        T.erase({hei[i],i});
        B.upd(m[hei[i]],{-hei[i],-1});
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
