#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<int> b;
multiset<int> d;

void rem(int x) {
    auto p=b.find(x);
    int L=*prev(p), R=*next(p);
    d.erase(d.find(x-L));
    d.erase(d.find(R-x));
    d.insert(R-L);
    b.erase(x);
}

void add(int x) {
    auto p=b.insert(x).first;
    int L=*prev(p), R=*next(p);
    if (d.find(R-L)==d.end()) cout << "??\n" << endl;
    d.erase(d.find(R-L));
    d.insert(x-L);
    d.insert(R-x);
    b.insert(x);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    string s;
    cin >> s;
    int n=sz(s);
    vi x(n+2);
    x[0]=x[n+1]=-1;
    rep(i, 0, n) x[i+1]=s[i]-'0';
    rep(i, 0, n+1) if (x[i]!=x[i+1]) {
        if (sz(b)) d.insert(i-*b.rbegin());
        b.insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        if (x[a]==x[a+1]) add(a);
        if (x[a]==x[a-1]) add(a-1);
        x[a]^=1;
        if (x[a]==x[a+1]) rem(a);
        if (x[a]==x[a-1]) rem(a-1);
        cout << *d.rbegin() << " \n"[q==0];
    }
    return 0;
}
