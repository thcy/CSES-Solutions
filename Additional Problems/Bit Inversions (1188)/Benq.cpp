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
int m;
multiset<int> ans,ret;

void modify(int x) {
    if (x == 0 || x == sz(s)) return;
    if (ans.count(x)) {
        auto it = ans.find(x);
        int a = *prev(it), b = *next(it);
        ret.erase(ret.find(x-a)), ret.erase(ret.find(b-x));
        ret.insert(b-a);
        ans.erase(it);
    } else {
        ans.insert(x);
        auto it = ans.find(x);
        int a = *prev(it), b = *next(it);
        ret.erase(ret.find(b-a));
        ret.insert(x-a), ret.insert(b-x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> m;
    ans.insert(0);
    ans.insert(sz(s));
    F0R(i,sz(s)-1) if (s[i] != s[i+1]) ans.insert(i+1);
    for (auto it = ans.begin(); next(it) != ans.end(); it ++)
        ret.insert(*next(it)-*it);
    
    F0R(i,m) {
        int x; cin >> x;
        modify(x-1); modify(x);
        cout << *ret.rbegin() << " ";
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
