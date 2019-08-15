// https://cses.fi/problemset/task/1091/
// Concert Tickets
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        mp[a]++;
    }
    while (m--) {
        int a;
        scanf("%d", &a);
        auto it = mp.upper_bound(a);
        if (it == mp.begin())
            printf("-1\n");
        else {
            it--;
            printf("%d\n", it->first);
            if (--it->second == 0)
                mp.erase(it);
        }
    }
    return 0;
}
