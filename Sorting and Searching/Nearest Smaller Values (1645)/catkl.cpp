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
    
    int n;
    cin >>n;
    vector<pii> s{{0, 0}};
    rep(i, 1, n+1) {
        int a;
        cin >> a;
        while (s.back().first>=a)
            s.pop_back();
        cout << s.back().second << " \n"[i==n];
        s.push_back({a, i});
    }
    return 0;
}
