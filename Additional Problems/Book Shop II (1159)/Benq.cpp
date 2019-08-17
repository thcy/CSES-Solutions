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

int n,x,h[100],s[100], k[100], bes[100001];

void ad(int a, int b) {
    F0Rd(j,x-a+1) bes[j+a] = max(bes[j+a],bes[j]+b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    F0R(i,n) cin >> h[i];
    F0R(i,n) cin >> s[i];
    F0R(i,n) cin >> k[i];
    F0R(i,n) {
        int t = 1;
        while (k[i] >= t) {
            ad(t*h[i],t*s[i]);
            k[i] -= t; t *= 2;
        }
        if (k[i] > 0) ad(k[i]*h[i],k[i]*s[i]);
    }
    cout << bes[x];
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
