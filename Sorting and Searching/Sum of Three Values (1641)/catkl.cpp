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
    
    int n,  x;
    cin >> n >> x;
    vector<pii> a(n);
    rep(i, 0, n) {
        cin >> a[i].first;
        a[i].second=i+1;
    }
    sort(all(a));
    rep(i, 0, n) {
        int L=0, R=n-1;
        int y=x-a[i].first;
        while(L<i && R>i) {
            int z=a[L].first+a[R].first;
            if (z==y) {
                cout << a[L].second << " " << a[i].second << " "
                << a[R].second << '\n';
                return 0;
            }
            if (z<y) L++;
            else R--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
