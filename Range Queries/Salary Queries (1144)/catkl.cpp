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

void example() {
    Tree<int> t, t2; t.insert(8);
    auto it = t.insert(10).first;
    assert(it == t.lower_bound(9));
    assert(t.order_of_key(10) == 1);
    assert(t.order_of_key(11) == 2);
    assert(*t.find_by_order(0) == 8);
    t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi x(n+1);
    Tree<pii> t;
    rep(i, 1, n+1) {
        cin >> x[i];
        t.insert({x[i], i});
    }
    rep(i, 0, q) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if (ch=='!') {
            t.erase({x[a], a});
            x[a]=b;
            t.insert({x[a], a});
        }
        else {
            int L=t.order_of_key({a, 0});
            int R=t.order_of_key({b+1, 0});
            cout << R-L << '\n';
        }
    }
    return 0;
}
