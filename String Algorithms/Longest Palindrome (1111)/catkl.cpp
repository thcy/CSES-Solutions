#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi,2> p = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
        int t = r-i+!z;
        if (i<r) p[z][i] = min(t, p[z][l+t]);
        int L = i-p[z][i], R = i+p[z][i]-!z;
        while (L>=1 && R+1<n && s[L-1] == s[R+1])
            p[z][i]++, L--, R++;
        if (R>r) l=L, r=R;
    }
    return p;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    string s;
    cin >> s;
    auto p=manacher(s);
    int i0=max_element(all(p[0]))-begin(p[0]);
    int i1=max_element(all(p[1]))-begin(p[1]);
    if (2*p[0][i0]>2*p[1][i1]+1)
        cout << s.substr(i0-p[0][i0], 2*p[0][i0]) << '\n';
    else
        cout << s.substr(i1-p[1][i1], 2*p[1][i1]+1) << '\n';
    return 0;
}
