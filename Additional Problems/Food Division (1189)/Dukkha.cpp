// https://cses.fi/problemset/task/1189
// Food Division
// practice with rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 500000;

long long aa[N];

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        aa[i] = x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        aa[i] -= x;
    }
    for (int i = 1; i < n; i++)
        aa[i] += aa[i - 1];
    sort(aa, aa + n);
    long long med = aa[n / 2], ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(aa[i] - med);
    printf("%lld\n", ans);
    return 0;
}
