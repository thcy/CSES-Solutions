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
    if (n==2 || n==3)
    cout << "NO SOLUTION\n";
    else {
        for(int i=2; i<=n; i+=2)
        cout << i << " ";
        for(int i=1; i<=n; i+=2)
        cout << i << " \n"[i+2>n];
    }
    return 0;
}
