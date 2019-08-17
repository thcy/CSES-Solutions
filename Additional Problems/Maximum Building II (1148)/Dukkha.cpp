// https://cses.fi/problemset/task/1148
// Building II
// practice with rainboy
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int N = 1000;

char cc[N][N + 1];
int ll[N][N], rr[N][N];
bool alive[N][N];

pii *ee[N + 1];
int kk[N + 1];

int pp[N + 1], aa[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", cc[i]);
    for (int j = 0; j < m; j++) {
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (cc[i][j] == '*')
                d = 0;
            else
                d++;
            kk[d]++;
        }
    }
    for (int d = 0; d <= n; d++) {
        ee[d] = new pii[kk[d]];
        kk[d] = 0;
    }
    for (int j = 0; j < m; j++) {
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (cc[i][j] == '*')
                d = 0;
            else
                d++;
            auto &e = ee[d][kk[d]++];
            e.first = i;
            e.second = j;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ll[i][j] = rr[i][j] = j;
    for (int d = n; d > 0; d--) {
        for (int h = 0; h < kk[d]; h++) {
            auto &e = ee[d][h];
            int i = e.first;
            int j = e.second;
            alive[i][j] = true;
            int l, r;
            l = r = j;
            if (j > 0 && alive[i][j - 1]) {
                l = ll[i][j - 1];
                pp[j - l]--;
            }
            if (j < m - 1 && alive[i][j + 1]) {
                r = rr[i][j + 1];
                pp[r - j]--;
            }
            rr[i][l] = r;
            ll[i][r] = l;
            pp[r - l + 1]++;
        }
        auto &qq = aa[d - 1];
        for (int j = 1; j <= m; j++)
            qq[j - 1] = pp[j];
        for (int j = m - 2; j >= 0; j--)
            qq[j] += qq[j + 1];
        for (int j = m - 2; j >= 0; j--)
            qq[j] += qq[j + 1];
    }
    for (int d = 0; d < n; d++) {
        for (int j = 0; j < m; j++)
            printf("%d ", aa[d][j]);
        printf("\n");
    }
    return 0;
}
