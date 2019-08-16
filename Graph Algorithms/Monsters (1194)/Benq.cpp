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

int r,c, dist[2500][2500], DIST[2500][2500];
char g[2500][2500];
pii st;
queue<pii> q;

int xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};
string pre = "URDL", ans;

bool valid(pii x) {
    return x.f >= 0 && x.f < c && x.s >= 0 && x.s < r && g[x.f][x.s] != '#';
}

void solve(int x, int y) {
    pii z = {x,y};
    while (z != st) {
        F0R(i,4) {
            pii Z = {z.f+xdir[i],z.s+ydir[i]};
            if (!valid(Z)) continue;
            if (dist[Z.f][Z.s] < dist[z.f][z.s]) {
                ans += pre[i^2];
                z = Z;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    F0Rd(j,r) F0R(i,c) {
        dist[i][j] = DIST[i][j] = MOD;
        cin >> g[i][j];
        if (g[i][j] == 'A') st = {i,j};
    }
    
    dist[st.f][st.s] = 0;
    q.push(st);
    while (sz(q)) {
        pii x = q.front(); q.pop();
        F0R(i,4) {
            pii X = {x.f+xdir[i],x.s+ydir[i]};
            if (!valid(X) || dist[X.f][X.s] != MOD) continue;
            dist[X.f][X.s] = dist[x.f][x.s]+1;
            q.push(X);
        }
    }
    F0R(i,c) F0R(j,r) {
        DIST[i][j] = MOD;
        if (g[i][j] == 'M') {
            DIST[i][j] = 0;
            q.push({i,j});
        }
    }
    while (sz(q)) {
        pii x = q.front(); q.pop();
        F0R(i,4) {
            pii X = {x.f+xdir[i],x.s+ydir[i]};
            if (!valid(X) || DIST[X.f][X.s] != MOD) continue;
            DIST[X.f][X.s] = DIST[x.f][x.s]+1;
            q.push(X);
        }
    }
    
    F0R(i,c) F0R(j,r) if ((i == 0 || i == c-1 || j == 0 || j == r-1) && valid({i,j})
                          && dist[i][j] < DIST[i][j]) {
        solve(i,j);
        reverse(all(ans));
        cout << "YES\n" << sz(ans) << "\n";
        cout << ans;
        return 0;
    }
    cout << "NO";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
