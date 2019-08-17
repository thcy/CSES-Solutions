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
const int MOD = 1000000007;

int n, p[MX], pos[MX];

ll solve1() {
    Tree<int> T;
    ll ans = 0;
    FOR(i,1,n+1) {
        ans += sz(T)-T.order_of_key(p[i]);
        T.insert(p[i]);
    }
    return ans;
}

bool done[MX];

int solve2() {
    int ans = 0;
    FOR(i,1,n+1) if (!done[i]) {
        int cur = p[i];
        int z = 0;
        while (cur != i) {
            done[cur] = 1;
            cur = p[cur];
            z ++;
        }
        done[cur] = 1;
        ans += z;
    }
    return ans;
}


vi bes = {0};

void ad(int x) {
    int lo = 0, hi = sz(bes)-1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (bes[mid] < x) lo = mid;
        else hi = mid-1;
    }
    if (lo == sz(bes)-1) bes.pb(0);
    bes[lo+1] = x;
}

int solve3() {
    FOR(i,1,n+1) ad(p[i]);
    return n-(sz(bes)-1);
}

int solve4() {
    int cur = MOD;
    FORd(i,1,n+1) {
        if (pos[i] < cur) cur = pos[i];
        else return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    cout << solve1() << " " << solve2() << " " << solve3() << " " << solve4();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
