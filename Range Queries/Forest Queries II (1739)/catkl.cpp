#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N=1024;
int ft[N][N];

void update(int i, int j, int d) {
    for(; i<N; i+=i&-i)
        for(int k=j; k<N; k+=k&-k)
            ft[i][k]+=d;
}

int query(int i, int j) {
    int ans=0;
    for(; i; i-=i&-i)
        for(int k=j; k; k-=k&-k)
            ans+=ft[i][k];
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, n) if (s[i][j]=='*')
            update(i+1, j+1, 1);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type==1) {
            int i, j;
            cin >> i >> j;
            if(s[i-1][j-1]=='*')
                update(i, j, -1), s[i-1][j-1]='.';
            else
                update(i, j, +1), s[i-1][j-1]='*';
        }
        else {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            int ans=query(i2, j2)+query(i1-1, j1-1);
            ans-=query(i2, j1-1)+query(i1-1, j2);
            cout << ans << '\n';
        }
    }
    return 0;
}
