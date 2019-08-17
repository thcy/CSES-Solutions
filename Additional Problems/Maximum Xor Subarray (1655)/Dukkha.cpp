// https://cses.fi/problemset/task/1655
// Maximum Xor Subarray
// practice with rainboy

#include <iostream>

using namespace std;

const int N = 200000, K = 30, B = 1 << (K - 1);
int tt[N * K + 2][2], m;

void update(int x) {
    int i = 1;
    for (int b = B; b != 0; b >>= 1) {
        int j = (x & b) == 0 ? 0 : 1;
        if (tt[i][j] == 0)
            tt[i][j] = ++m;
        i = tt[i][j];
    }
}

int query(int x) {
    int i = 1;
    for (int b = B; b != 0; b >>= 1) {
        int j = (x & b) == 0 ? 0 : 1;
        if (tt[i][j ^ 1] != 0) {
            j ^= 1;
            x |= b;
        } else
            x &= ~b;
        i = tt[i][j];
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    int x = 0, ans = 0;
    m = 1;
    while (n-- > 0) {
        int a;
        scanf("%d", &a);
        update(x);
        x ^= a;
        ans = max(ans, query(x));
    }
    printf("%d\n", ans);
    return 0;
}
