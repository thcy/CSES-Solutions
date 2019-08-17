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
__gnu_pbds::gp_hash_table<string,int,hash<string>>
d({},{},{},{},{1<<16});

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    string t, ta;
    rep(i, 0, 9) {
        cin >> ta;
        t+=ta;
    }
    vector<pii> sw;
    rep(i, 0, 3) rep(j, 0, 2) {
        sw.push_back({3*i+j, 3*i+j+1});
        sw.push_back({3*j+i, 3*(j+1)+i});
    }
    string s="123456789";
    d[s]=1;
    queue<string> q;
    for(q.push(s); !q.empty(); q.pop()) {
        s=q.front();
        int cur=d[s];
        if (s==t) break;
        trav(p, sw) {
            swap(s[p.first], s[p.second]);
            if (!d[s])
                d[s]=cur+1, q.push(s);
            swap(s[p.first], s[p.second]);
        }
    }
    cout << d[t]-1 << '\n';
    return 0;
}
