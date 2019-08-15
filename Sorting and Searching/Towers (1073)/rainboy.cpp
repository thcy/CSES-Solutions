/*
 https://cses.fi/problemset/task/1073
 Towers
 */
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        auto it = mp.upper_bound(a);
        if (it == mp.end())
            k++;
        else if (--it->second == 0)
            mp.erase(it);
        mp[a]++;
    }
    printf("%d\n", k);
    return 0;
}
