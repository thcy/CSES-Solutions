#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

struct T {
    ll x1, y1, x2, y2;
    int id;
};

constexpr ll inf=1e18;
map<char, int> c2dir{{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
vi dx{0, 0, -1, 1}, dy{1, -1, 0, 0};
vector<T> f;

int isect(ll id, ll L, ll R) {
    ll y1=f[id].y1, y2=f[id].y2;
    ll l=min(y1, y2), r=max(y1, y2);
    return (r>=L && l<=R);
}

ll isectd(int id, int w) {
    ll x1=f[id].x1, y1=f[id].y1, x2=f[id].x2, y2=f[id].y2;
    ll X1=f[w].x1, Y1=f[w].y1, X2=f[w].x2, Y2=f[w].y2;
    if (x1!=x2) {
        swap(x1, y1); swap(x2, y2);
        swap(X1, Y1); swap(X2, Y2);
    }
    if (X1!=X2) {
        if (Y1<min(y1, y2) || Y1>max(y1, y2)) return inf;
        if (max(X1, X2)<x1 || min(X1, X2)>x1) return inf;
        return abs(y1-Y1);
    }
    else {
        if (x1!=X1) return inf;
        if (max(y1, y2)<min(Y1, Y2)) return inf;
        if (min(y1, y2)>max(Y1, Y2)) return inf;
        if (y1>=min(Y1, Y2) && y1<=max(Y1, Y2)) return 0;
        if (Y1>y1) return min(Y1, Y2)-y1;
        if (Y1<y1) return y1-max(Y1, Y2);
    }
    return inf;
}

int processXX(int M) {
    map<ll, set<pll>> s;
    rep(i, 0, M) if (f[i].x1==f[i].x2) {
        T q=f[i];
        auto &t=s[q.x1];
        auto p=t.lower_bound({q.y1, -inf});
        if (p!=end(t) && isect(q.id, p->first, p->second))
            return 1;
        if (p!=begin(t) && isect(q.id, prev(p)->first, prev(p)->second))
            return 1;
        t.insert({min(q.y1, q.y2), max(q.y1, q.y2)});
    }
    return 0;
}

int processXY(int M) {
    vector<pll> e;
    rep(i, 0, M) {
        T q=f[i];
        if (q.x1==q.x2)
            e.push_back({q.x1, q.id});
        else {
            e.push_back({min(q.x1, q.x2), -inf-q.id});
            e.push_back({max(q.x1, q.x2), +inf+q.id});
        }
    }
    sort(all(e));
    map<ll, ll> t;
    trav(q, e) {
        ll id=q.second;
        if (id<=-inf) {
            ll y=f[-inf-id].y1;
            ++t[y];
        }
        else if (id>=+inf) {
            ll y=f[id-inf].y1;
            if (--t[y]==0) t.erase(y);
        }
        else {
            auto p=t.lower_bound(f[id].y1);
            if (p!=end(t) && isect(id, p->first, p->first))
                return 1;
            if (p!=begin(t) && isect(id, prev(p)->first, prev(p)->first))
                return 1;
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    f.resize(n);
    string s(n, 0);
    ll x=0, y=0;
    rep(i, 0, n) {
        ll d;
        cin >> s[i] >> d;
        int dir=c2dir[s[i]];
        f[i].x1=x+(i>0)*dx[dir];
        f[i].y1=y+(i>0)*dy[dir];
        x=f[i].x2=x+d*dx[dir];
        y=f[i].y2=y+d*dy[dir];
        f[i].id=i;
    }
    int L=0, R=n;
    while (L<R) {
        int M=(L+R)/2;
        int fail=processXX(M+1) || processXY(M+1);
        trav(q, f) {
            swap(q.x1, q.y1);
            swap(q.x2, q.y2);
        }
        if (!fail)
            fail|=processXX(M+1) || processXY(M+1);
        if (fail) R=M;
        else L=M+1;
    }
    ll ans=0;
    rep(i, 0, L)
    ans+=(i>0)+abs(f[i].x1-f[i].x2)+abs(f[i].y1-f[i].y2);
    if (L<n) {
        ll d=inf;
        rep(i, 0, L)
        d=min(d, isectd(L, i));
        ans+=1+d;
    }
    if (L<n && (c2dir[s[L]]^c2dir[s[L-1]])==1)
        ans--;
    cout << ans << '\n';
    return 0;
}
