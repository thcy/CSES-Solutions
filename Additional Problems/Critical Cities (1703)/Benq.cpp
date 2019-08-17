// equivalent to USACO sweetgrass :o

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;

#define F0R(i,a) for (int i = 0; i < a; ++i)
#define F0Rd(i,a) for (int i = a-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i < b; ++i)

#define all(a) a.begin(), a.end()
#define sz(a) int((a).size())
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MOD = 1000000007;
const int MX = 100001;

int N,M, pre[MX], nex[MX], bad[MX], pos[MX];
vi adj[MX], radj[MX];

void gen(int x) {
    for (int i: adj[x]) if (!pre[i] && i != 1) {
        pre[i] = x;
        gen(i);
    }
}

void dfsPre(int x, int y) {
    for (int i: radj[x]) if (!nex[i]) {
        nex[i] = y;
        if (!bad[i]) dfsPre(i,y);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,M) {
        // int a = rand() % N+1,b = rand() % N+1;
        int a,b; cin >> a >> b;
        if (a == b) continue;
        adj[a].pb(b); radj[b].pb(a);
    }
    gen(1);
    vi al;
    for (int x = N; x; x = pre[x]) {
        bad[x] = 1;
        al.pb(x);
    }
    reverse(all(al));
    F0Rd(i,sz(al)) {
        int x = al[i];
        pos[x] = i+1;
        dfsPre(x,x);
    }
    
    int bes = 0;
    vi ans;
    F0R(I,sz(al)-2) {
        int i = al[I];
        bes = max(bes,pos[nex[i]]);
        if (bes <= pos[al[I+1]]) ans.pb(al[I+1]);
    }
    ans.pb(1), ans.pb(N);
    cout << sz(ans) << "\n";
    sort(all(ans));
    for (int i: ans) cout << i << " ";
}
