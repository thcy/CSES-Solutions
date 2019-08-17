#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    trav(e,g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));
    
    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n), gr(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    vi repr;
    scc(g, [&](vi &c){
        repr.push_back(c[0]);
    });
    if (ncomps==1) {
        cout << "0\n";
        return 0;
    }
    vector<vi> gc(ncomps), gcr(ncomps);
    vi issrc(ncomps, 1), issnk(ncomps, 1);
    rep(i, 0, n) trav(j, g[i]) {
        if (comp[i]==comp[j]) continue;
        gc[comp[i]].push_back(comp[j]);
        gcr[comp[j]].push_back(comp[i]);
        issnk[comp[i]]=issrc[comp[j]]=0;
    }
    vi dsrc(ncomps, -1), dsnk(ncomps, -1);
    for(int i=0; i<ncomps; i++) {
        if (issnk[i]) dsnk[i]=i;
        trav(j, gcr[i]) dsnk[j]=dsnk[i];
    }
    for(int i=ncomps-1; i>=0; i--) {
        if (issrc[i]) dsrc[i]=i;
        trav(j, gc[i]) dsrc[j]=dsrc[i];
    }
    vi L(ncomps, -1), R(ncomps, -1), dL(ncomps), dR(ncomps);
    int nL=0, nR=0;
    rep(i, 0, ncomps) {
        if (issrc[i]) {
            L[i]=dsnk[i];
            dR[L[i]]++;
            nL++;
        }
        if (issnk[i]) {
            R[i]=dsrc[i];
            dL[R[i]]++;
            nR++;
        }
    }
    vi L0, R0;
    rep(i, 0, ncomps) {
        if(L[i]>=0 && dL[i]==0) L0.push_back(i);
        if(R[i]>=0 && dR[i]==0) R0.push_back(i);
    }
    auto remove=[&](int i, vi &A, vi &B0, vi &dB, int &nA) {
        nA--;
        if (--dB[A[i]]==0) B0.push_back(A[i]);
        A[i]=-1;
    };
    vector<pii> ans;
    for(;;) {
        if (sz(L0) && sz(R0)) {
            int l=L0.back(), r=R0.back();
            L0.pop_back(), R0.pop_back();
            ans.push_back({r, l});
            remove(l, L, R0, dR, nL);
            remove(r, R, L0, dL, nR);
        }
        else if (sz(L0) && nL>nR) {
            int l=L0.back();
            L0.pop_back();
            ans.push_back({L[l], l});
            remove(l, L, R0, dR, nL);
        }
        else if (sz(R0) && nR>nL) {
            int r=R0.back();
            R0.pop_back();
            ans.push_back({r, R[r]});
            remove(r, R, L0, dL, nR);
        }
        else if (!sz(R0)) {
            vi Ls, Rs;
            rep(i, 0, ncomps) if(L[i]>=0) {
                Ls.push_back(i);
                Rs.push_back(L[i]);
            }
            rep(i, 0, sz(Ls))
            ans.push_back({Rs[i], Ls[(i+1)%sz(Ls)]});
            break;
        }
        else if (!sz(L0)) {
            vi Ls, Rs;
            rep(i, 0, ncomps) if(R[i]>=0) {
                Rs.push_back(i);
                Ls.push_back(R[i]);
            }
            rep(i, 0, sz(Ls))
            ans.push_back({Rs[i], Ls[(i+1)%sz(Ls)]});
            break;
        }
    }
    cout << sz(ans) << '\n';
    trav(p, ans)
    cout << repr[p.first]+1 << " " << repr[p.second]+1 << '\n';
    return 0;
}
