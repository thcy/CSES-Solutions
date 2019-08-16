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

const int MX = 200001;

int n;

struct HeavyLightSet {
    int loc[MX], sub[MX], val[MX], ans[MX];
    vi child[MX];
    set<int> dat[MX];
    
    void comb(int a, int b) {
        int A = loc[a], B = loc[b];
        if (sz(dat[A]) < sz(dat[B])) swap(a,b), swap(A,B);
        for (int x: dat[B]) dat[A].insert(x);
        dat[B].clear(); loc[b] = A;
    }
    
    void process(int ind, int pre) {
        sub[ind] = 1; loc[ind] = ind; dat[ind].insert(val[ind]);
        for (int i: child[ind]) if (i != pre) {
            process(i,ind);
            comb(i,ind);
            sub[ind] += sub[i];
        }
        ans[ind] = sz(dat[loc[ind]]);
        // now do stuff with values
    }
};

HeavyLightSet H;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) cin >> H.val[i];
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        H.child[a].pb(b), H.child[b].pb(a);
    }
    H.process(1,0);
    FOR(i,1,n+1) cout << H.ans[i] << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
