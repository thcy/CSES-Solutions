#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

char g[2500][2500];
int n,m;
int xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};
bool visit[2500][2500];
queue<pii> todo;

void process(pii x) {
    if (visit[x.f][x.s]) return;
    visit[x.f][x.s] = 1;
    F0R(i,4) {
        pii y = {x.f+xdir[i],x.s+ydir[i]};
        if (y.f < 0 || y.f >= n || y.s < 0 || y.s >= m || g[y.f][y.s] == '#') continue; // ignore this point if it's outside of grid
        process(y);
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) F0R(j,m) cin >> g[i][j];
    
    int ans = 0;
    F0R(i,n) F0R(j,m) if (g[i][j] == '.' && !visit[i][j]) {
        process({i,j});
        ans ++;
    }
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
