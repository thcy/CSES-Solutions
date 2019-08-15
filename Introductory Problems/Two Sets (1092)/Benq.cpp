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

vi a,b;

void solve(int n) {
    if (n == 3) {
        a.pb(3);
        b.pb(1), b.pb(2);
        return;
    }
    if (n == 0) return;
    a.pb(n), a.pb(n-3), b.pb(n-1), b.pb(n-2);
    solve(n-4);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO";
        return 0;
    }
    solve(n);
    cout << "YES\n";
    cout << sz(a) << "\n";
    for (int i: a) cout << i << " ";
    cout << "\n";
    cout << sz(b) << "\n";
    for (int i: b) cout << i << " ";
    cout << "\n";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
