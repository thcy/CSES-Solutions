#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    Tree<pii> t;
    rep(i, 0, n) {
        int a;
        cin >> a;
        t.insert({i, a});
    }
    rep(i, 0, n) {
        int a;
        cin >> a;
        auto p=t.find_by_order(a-1);
        cout << p->second << " \n"[i==n-1];
        t.erase(p);
    }
    return 0;
}
