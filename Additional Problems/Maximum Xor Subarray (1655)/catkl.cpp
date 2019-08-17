#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int B=30;
vector<array<int, 2>> T(2);

void insert(int x) {
    int i=1;
    for (int b=B; b>=0; b--) {
        int w=(x>>b)&1;
        if (!T[i][w]) {
            T[i][w]=sz(T);
            T.push_back({0, 0});
        }
        i=T[i][w];
    }
}

int query(int x) {
    int i=1, val=0;
    for (int b=B; b>=0; b--) {
        int w=(x>>b)&1;
        if (T[i][w^1])
            w^=1, val|=1<<b;
        i=T[i][w];
    }
    return val;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    insert(0);
    int s=0, ans=0;
    while (n--) {
        int a;
        cin >> a;
        s^=a;
        ans=max(ans, query(s));
        insert(s);
    }
    cout << ans << '\n';
    return 0;
}
