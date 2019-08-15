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
    cin >> n;
    if(n%4==1 || n%4==2)
    cout << "NO\n";
    else {
        vi a[2];
        if(n%4==3) a[0]={1, 2}, a[1]={3};
        for(int i=n%4+1; i<n; i+=4) {
            a[0].push_back(i), a[0].push_back(i+3);
            a[1].push_back(i+1), a[1].push_back(i+2);
        }
        cout << "YES\n";
        rep(i, 0, 2) {
            cout << sz(a[i]) << '\n';
            rep(j, 0, sz(a[i]))
            cout << a[i][j] << " \n"[j==sz(a[i])-1];
        }
    }
    return 0;
}
