// practice with rainboy
// https://cses.fi/problemset/task/1164
// Room Allocation
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int aa[N], bb[N];

struct V {
    int i, x;
} vv[N * 2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &aa[i], &bb[i]);
        bb[i]++;
    }
    for (int i = 0; i < n; i++)
        for (int lr = 0; lr <= 1; lr++) {
            V &u = vv[i * 2 + lr];
            u.i = i;
            u.x = (lr == 0 ? aa : bb)[i] * 2 + 1 - lr;
        }
    sort(vv, vv + n * 2, [] (V &u, V &v) { return u.x < v.x; });
    int *stack = aa, *cc = bb;
    int cnt = 0, k = 0;
    for (int h = 0; h < n * 2; h++) {
        V &u = vv[h];
        if (u.x % 2 == 1)
            cc[u.i] = cnt == 0 ? ++k : stack[--cnt];
        else
            stack[cnt++] = cc[u.i];
    }
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
        printf("%d ", cc[i]);
    printf("\n");
}
