#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    while (n--) {
        int a;
        cin >> a;
        h.insert(a);
    }
    while (m--) {
        int a;
        cin >> a;
        auto p=h.lower_bound(a+1);
        if (p==h.begin()) cout << "-1\n";
        else {
            --p;
            cout << *p << '\n';
            h.erase(p);
        }
    }
    return 0;
}
