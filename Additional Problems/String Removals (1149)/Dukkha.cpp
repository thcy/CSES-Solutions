// https://cses.fi/problemset/task/1149
// String Removals
// practice with rainboy
#include <iostream>

using namespace std;

const int MD = 1000000007;

int main() {
    static char cc[500001];
    scanf("%s", cc);
    static int kk[26];
    int k = 0;
    for (int i = 0; cc[i]; i++) {
        int c = cc[i] - 'a';
        int kc = kk[c];
        kk[c] = k + 1;
        k = (k + (kk[c] - kc) % MD) % MD;
    }
    printf("%d\n", (k + MD) % MD);
    return 0;
}
