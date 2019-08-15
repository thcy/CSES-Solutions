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

multiset<int> len, pos;
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    pos.insert(0), pos.insert(n), len.insert(n);
    F0R(i,k) {
        int x; cin >> x;
        pos.insert(x); auto it = pos.find(x);
        int a = *prev(it), b = *next(it);
        len.erase(len.find(b-a));
        len.insert(x-a), len.insert(b-x);
        cout << *len.rbegin() << " ";
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
