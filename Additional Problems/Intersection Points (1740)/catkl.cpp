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
    
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> e;
    rep(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2) e.push_back({x1, 0, y1, y2});
        else {
            e.push_back({min(x1, x2), -1, y1, 0});
            e.push_back({max(x1, x2), +1, y1, 0});
        }
    }
    sort(all(e));
    Tree<int> t;
    ll ans=0;
    trav(p, e) {
        int x, type, a, b;
        tie(x, type, a, b)=p;
        if (type==-1) t.insert(a);
        if (type==+1) t.erase(a);
        if (type==0) {
            if(a>b) swap(a, b);
            ans+=t.order_of_key(b+1)-t.order_of_key(a);
        }
    }
    cout << ans << '\n';
    return 0;
}
