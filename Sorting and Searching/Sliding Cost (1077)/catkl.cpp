#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

multiset<int, greater<int>> L;
multiset<int, less<int>> R;
ll SL, SR;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, k;
    cin >> n >> k;
    vi x(n);
    rep(i, 0, n) {
        cin >> x[i];
        if (x[i]<=*begin(L) )
            L.insert(x[i]), SL+=x[i];
        else
            R.insert(x[i]), SR+=x[i];
        if (i>=k) {
            auto p=L.find(x[i-k]);
            if (p!=end(L))
                L.erase(p), SL-=x[i-k];
            else
                R.erase(R.find(x[i-k])), SR-=x[i-k];
        }
        while (sz(L)>sz(R)+1) {
            int b=*begin(L);
            R.insert(b), SR+=b;
            L.erase(begin(L)), SL-=b;
        }
        while(sz(L)<sz(R)) {
            int b=*begin(R);
            L.insert(b), SL+=b;
            R.erase(begin(R)), SR-=b;
        }
        if(i>=k-1) {
            ll m=*begin(L);
            cout << m*(sz(L)-sz(R))-SL+SR << " \n"[i==n-1];
        }
    }
    return 0;
}
