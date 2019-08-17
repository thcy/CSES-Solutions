// https://cses.fi/problemset/task/1161
// Stick Divisions
// practice with rainboy
#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int get() {
    auto it = mp.begin();
    int x = it->first;
    if (it->second == 1)
        mp.erase(it);
    else
        it->second--;
    return x;
}

int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mp[x]++;
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = get() + get();
        mp[x]++;
        ans += x;
    }
    printf("%lld\n", ans);
    return 0;
}
