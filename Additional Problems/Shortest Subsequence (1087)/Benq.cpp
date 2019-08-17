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

string s;
int S[1<<20], nex[1<<20][4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    F0R(i,sz(s)) {
        switch (s[i]) {
            case 'A':
                S[i] = 0;
                break;
            case 'C':
                S[i] = 1;
                break;
            case 'G':
                S[i] = 2;
                break;
            default:
                S[i] = 3;
        }
    }
    F0R(i,4) nex[sz(s)][i] = sz(s)+1;
    F0Rd(i,sz(s)) {
        F0R(j,4) nex[i][j] = nex[i+1][j];
        nex[i][S[i]] = i+1;
    }
    int cur = 0;
    string ret = "ACGT";
    while (cur < sz(s)+1) {
        pii bes = {-1,-1};
        F0R(i,4) bes = max(bes,{nex[cur][i],i});
        cout << ret[bes.s];
        cur = bes.f;
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
