#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> s(8);
vi h(8), d1(16), d2(16);
int ans;

void dfs(int i) {
    if(i==8) {
        ans++;
        return;
    }
    rep(j, 0, 8) {
        if(h[j] || d1[i+j] || d2[i-j+8] || s[i][j]=='*')
            continue;
        h[j]=d1[i+j]=d2[i-j+8]=1;
        dfs(i+1);
        h[j]=d1[i+j]=d2[i-j+8]=0;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    rep(i, 0, 8) cin >> s[i];
    dfs(0);
    cout << ans << '\n';
    return 0;
}
