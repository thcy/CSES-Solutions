// https://cses.fi/problemset/task/1202
// Investigation
// practice with rainboy
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 100000, MD = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

typedef pair<int, int> pii;

vector<pii> aa[N];
long long dd[N];
int kk[N], lmin[N], lmax[N];

struct Compare {
    bool operator() (int i, int j) const {
        return dd[i] < dd[j] || (dd[i] == dd[j] && i < j);
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int i, j, c;
        scanf("%d%d%d", &i, &j, &c);
        i--, j--;
        aa[i].push_back({ j, c });
    }
    set<int, Compare> pq;
    for (int i = 0; i < n; i++)
        dd[i] = INF;
    dd[0] = 0;
    kk[0] = 1;
    lmin[0] = lmax[0] = 0;
    pq.insert(0);
    while (!pq.empty()) {
        auto it = pq.begin();
        int i = *it;
        pq.erase(it);
        for (auto &e : aa[i]) {
            int j = e.first, c = e.second;
            if (dd[j] >= dd[i] + c) {
                if (dd[j] != INF)
                    pq.erase(j);
                if (dd[j] > dd[i] + c) {
                    dd[j] = dd[i] + c;
                    kk[j] = kk[i];
                    lmin[j] = lmin[i] + 1;
                    lmax[j] = lmax[i] + 1;
                } else {
                    kk[j] = (kk[j] + kk[i]) % MD;
                    lmin[j] = min(lmin[j], lmin[i] + 1);
                    lmax[j] = max(lmax[j], lmax[i] + 1);
                }
                pq.insert(j);
            }
        }
    }
    printf("%lld %d %d %d\n", dd[n - 1], kk[n - 1], lmin[n - 1], lmax[n - 1]);
    return 0;
}
