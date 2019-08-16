// https://cses.fi/problemset/task/1133
// Tree Distances II
// practice with rainboy
#include <iostream>
#include <vector>

using namespace std;

const int N = 500000;

vector<int> aa[N];
int kk[N], n;
long long dd[N];

void dfs1(int p, int i) {
    long long d = 0;
    int k = 0;
    for (int j : aa[i])
        if (j != p) {
            dfs1(i, j);
            d += dd[j];
            k += kk[j];
        }
    dd[i] = d + k;
    kk[i] = k + 1;
}

void dfs2(int p, int i, long long d) {
    dd[i] = d;
    for (int j : aa[i])
        if (j != p)
            dfs2(i, j, dd[i] - kk[j] + n - kk[j]);
}

int main() {
    scanf("%d", &n);
    for (int h = 0; h < n - 1; h++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        aa[i].push_back(j);
        aa[j].push_back(i);
    }
    dfs1(-1, 0);
    dfs2(-1, 0, dd[0]);
    for (int i = 0; i < n; i++)
        printf("%lld ", dd[i]);
    printf("\n");
    return 0;
}
