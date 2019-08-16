// https://cses.fi/problemset/task/1099
// Stair Game
// practice with rainboy
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            int p;
            scanf("%d", &p);
            if (i % 2)
                x ^= p;
        }
        printf(x ? "first\n" : "second\n");
    }
    return 0;
}
