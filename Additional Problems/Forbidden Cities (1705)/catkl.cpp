#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
    int me = num[at] = ++Time, e, y, top = me;
    trav(pa, ed[at]) if (pa.second != par) {
        tie(y, e) = pa;
        if (num[y]) {
            top = min(top, num[y]);
            if (num[y] < me)
                st.push_back(e);
        } else {
            int si = sz(st);
            int up = dfs(y, e, f);
            top = min(top, up);
            if (up == me) {
                st.push_back(e);
                f(vi(st.begin() + si, st.end()));
                st.resize(si);
            }
            else if (up < me) st.push_back(e);
            else { f(vi{e}); }
        }
    }
    return top;
}

template<class F>
void bicomps(F f) {
    num.assign(sz(ed), 0);
    rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

typedef vector<pii> vpi;
typedef vector<vpi> graph;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    
    RMQ(const vector<T>& V) {
        int N = sz(V), on = 1, depth = 1;
        while (on < N) on *= 2, depth++;
        jmp.assign(depth, V);
        rep(i,0,depth-1) rep(j,0,N)
        jmp[i+1][j] = min(jmp[i][j],
                          jmp[i][min(N - 1, j + (1 << i))]);
    }
    
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    vi time;
    vector<ll> dist;
    RMQ<pii> rmq;
    
    LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}
    
    vpi dfs(graph& C) {
        vector<tuple<int, int, int, ll>> q(1);
        vpi ret;
        int T = 0, v, p, d; ll di;
        while (!q.empty()) {
            tie(v, p, d, di) = q.back();
            q.pop_back();
            if (d) ret.emplace_back(d, p);
            time[v] = T++;
            dist[v] = di;
            trav(e, C[v]) if (e.first != p)
                q.emplace_back(e.first, v, d+1, di + e.second);
        }
        return ret;
    }
    
    int query(int a, int b) {
        if (a == b) return a;
        a = time[a], b = time[b];
        return rmq.query(min(a, b), max(a, b)).second;
    }
    ll distance(int a, int b) {
        int lca = query(a, b);
        return dist[a] + dist[b] - 2 * dist[lca];
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m, q;
    cin >> n >> m >> q;
    ed.resize(n);
    vector<pii> e(m);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ed[a].push_back({b, i});
        ed[b].push_back({a, i});
        e[i]={a, b};
    }
    int nbcc=0;
    vi id(n);
    vector<pii> br;
    vector<vi> bcc(n);
    bicomps([&](const vi &c) {
        if (sz(c)==1) {
            int a=e[c[0]].first;
            int b=e[c[0]].second;
            br.push_back({a, b});
            id[a]=id[b]=1;
            return;
        }
        trav(i, c) for(int j: {e[i].first, e[i].second}) {
            if (!sz(bcc[j]) || bcc[j].back()!=nbcc)
                bcc[j].push_back(nbcc);
        }
        nbcc++;
    });
    int nap=0;
    rep(i, 0, n) {
        if (sz(bcc[i])>1 || id[i])
            id[i]=nbcc+(nap++);
        else id[i]=bcc[i][0];
    }
    graph T(nbcc+nap);
    trav(p, br) {
        T[id[p.first]].push_back({id[p.second], 1});
        T[id[p.second]].push_back({id[p.first], 1});
    }
    rep(i, 0, n) if(id[i]>=nbcc) {
        trav(j, bcc[i]) {
            T[id[i]].push_back({j, 1});
            T[j].push_back({id[i], 1});
        }
    }
    LCA lca(T);
    while (q--) {
        int a, b, c, ans=0;
        cin >> a >> b >> c;
        a--, b--, c--;
        if (a==c || b==c) ans=1;
        else if (id[c]<nbcc) ans=0;
        else {
            ll d1=lca.distance(id[a], id[c]);
            ll d2=lca.distance(id[b], id[c]);
            ll d=lca.distance(id[a], id[b]);
            ans=(d1+d2==d);
        }
        cout << (ans? "NO\n":"YES\n");
    }
    return 0;
}
