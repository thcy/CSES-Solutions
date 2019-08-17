// https://cses.fi/problemset/task/1203
// Visiting Cities
// practice with rainboy
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;

const int N = 100000;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

vector<pii> aa[N];
long long dd[N];
int pp[N], qq[N], cnt;
bool used[N], marked[N];

struct Compare {
    bool operator() (int i, int j) const {
        return dd[i] != dd[j] ? dd[i] < dd[j] : i < j;
    }
};

void dijkstra(int n) {
    set<int, Compare> pq;
    for (int i = 0; i < n; i++)
        dd[i] = INF;
    dd[0] = 0;
    pq.insert(0);
    while (!pq.empty()) {
        auto it = pq.begin();
        int i = *it;
        pq.erase(it);
        long long d = dd[i];
        for (auto &e : aa[i]) {
            int j = e.first;
            int c = e.second;
            if (dd[j] > d + c) {
                if (dd[j] != INF)
                    pq.erase(j);
                dd[j] = d + c;
                pp[j] = i;
                pq.insert(j);
            }
        }
    }
}

int i_;

void dfs(int i) {
    if (marked[i] && dd[i] > dd[i_])
        i_ = i;
    if (used[i])
        return;
    used[i] = true;
    long long d = dd[i];
    for (auto &e : aa[i]) {
        int j = e.first;
        int c = e.second;
        if (dd[j] == d + c)
            dfs(j);
    }
}

void solve(int n) {
    cnt = 0;
    for (int i = n - 1; i != 0; i = pp[i]) {
        marked[i] = used[i] = true;
        qq[cnt++] = i;
    }
    marked[0] = used[0] = true;
    qq[cnt++] = 0;
    while (cnt) {
        int i = qq[--cnt];
        if (i != i_)
            marked[i] = false;
        used[i] = false;
        dfs(i);
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
        if (marked[i])
            qq[cnt++] = i;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int i, j, c;
        scanf("%d%d%d", &i, &j, &c);
        i--, j--;
        aa[i].push_back({ j, c });
    }
    dijkstra(n);
    solve(n);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d ", qq[i] + 1);
    printf("\n");
    return 0;
}
