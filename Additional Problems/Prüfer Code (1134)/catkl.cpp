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
    vi x(n-2), d(n+1, 1);
    rep(i, 0, n-2) {
        cin >> x[i];
        d[x[i]]++;
    }
    priority_queue<int, vi, greater<int>> q;
    rep(i, 1, n+1)
    if (d[i]==1) q.push(i);
    rep(i, 0, n-2) {
        int j=q.top();
        q.pop();
        cout << j << " " << x[i] << '\n';
        if (--d[x[i]]==1) q.push(x[i]);
    }
    int i=q.top(); q.pop();
    int j=q.top(); q.pop();
    cout << i << " " << j << '\n';
    return 0;
}
