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

bool win[20][20][20];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    F0R(i,T) {
        int N,z=0; cin >> N;
        F0R(j,N) {
            int k; cin >> k;
            if (j&1) z ^= k;
        }
        if (z == 0) cout << "second\n";
        else cout << "first\n";
    }
    /*F0R(c,20) F0R(b,20) F0R(a,20) {
     int sum = a+b+c;
     if (sum == 0) continue;
     F0R(A,a) if (!win[A][b][c]) win[a][b][c] = 1;
     F0R(B,b) if (!win[a+b-B][B][c]) win[a][b][c] = 1;
     F0R(C,c) if (!win[a][b+c-C][C]) win[a][b][c] = 1;
     if (!win[a][b][c] && a+b+c < 20) cout << a << " " << b << " " << c << "\n";
     }*/
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
