// https://cses.fi/problemset/task/1196
// Flight Routes
// practice with rainboy
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 100000, K = 10;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

typedef pair<int, int> pii;

vector<pii> aa[N];
long long dd[N][K];

struct Compare {
    bool operator()(const pii &p, const pii &q) const {
        int pi = p.first, ph = p.second;
        int qi = q.first, qh = q.second;
        long long pd = dd[pi][ph], qd = dd[qi][qh];
        if (pd != qd) return pd < qd;
        return pi != qi ? pi < qi : ph < qh;
    }
};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int i, j, c;
        scanf("%d%d%d", &i, &j, &c);
        i--, j--;
        aa[i].push_back({ j, c });
    }
    for (int i = 0; i < n; i++)
        for (int h = 0; h < k; h++)
            dd[i][h] = INF;
    set<pii, Compare> pq;
    dd[0][0] = 0;
    pq.insert({ 0, 0 });
    while (!pq.empty()) {
        auto it = pq.begin();
        int i = it->first, h = it->second;
        pq.erase(it);
        long long d = dd[i][h];
        for (auto &e : aa[i]) {
            int i_ = e.first, c = e.second;
            for (int h_ = 0; h_ < k; h_++)
                if (dd[i_][h_] > d + c) {
                    long long d1 = d + c;
                    while (h_ < k && d1 != INF) {
                        long long d2 = dd[i_][h_];
                        if (d2 != INF)
                            pq.erase({ i_, h_ });
                        dd[i_][h_] = d1;
                        pq.insert({ i_, h_ });
                        d1 = d2;
                        h_++;
                    }
                    break;
                }
        }
    }
    for (int h = 0; h < k; h++)
        printf("%lld ", dd[n - 1][h]);
    printf("\n");
    return 0;
}
