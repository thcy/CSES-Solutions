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
const int MX = 200001;

set<pii> progress;
set<int> avail;
int n, ans[MX];
vector<array<int,3>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; v.resize(n);
    FOR(i,1,n+1)  {
        cin >> v[i-1][0] >> v[i-1][1];
        v[i-1][2] = i;
    }
    sort(all(v));
    int nex = 0;
    for (auto a: v) {
        while (sz(progress) && progress.begin()->f < a[0]) {
            avail.insert(progress.begin()->s);
            progress.erase(progress.begin());
        }
        if (sz(avail) == 0) avail.insert(++nex);
        ans[a[2]] = *avail.begin();
        progress.insert({a[1],*avail.begin()});
        avail.erase(avail.begin());
    }
    cout << nex << "\n";
    FOR(i,1,n+1) cout << ans[i] << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
