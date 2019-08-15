/*
 https://cses.fi/problemset/task/1076
 Sliding Median
 */
#include <iostream>
#include <map>

using namespace std;

const int N = 200000;

map<int, int> mp1, mp2;
int n1, n2;

void balance() {
    if (n1 < n2) {
        auto it = mp2.begin();
        if (--it->second == 0)
            mp2.erase(it);
        n2--;
        mp1[it->first]++, n1++;
    } else if (n1 > n2 + 1) {
        auto it = --mp1.end();
        if (--it->second == 0)
            mp1.erase(it);
        n1--;
        mp2[it->first]++, n2++;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    static int aa[N];
    for (int i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    for (int i = 0; i < n; i++) {
        int a = aa[i];
        if (mp1.lower_bound(a) != mp1.end())
            mp1[a]++, n1++;
        else
            mp2[a]++, n2++;
        balance();
        if (i >= k) {
            a = aa[i - k];
            if (mp1.lower_bound(a) != mp1.end()) {
                if (--mp1[a] == 0)
                    mp1.erase(a);
                n1--;
            } else {
                if (--mp2[a] == 0)
                    mp2.erase(a);
                n2--;
            }
            balance();
        }
        if (i >= k - 1)
            printf("%d ", (--mp1.end())->first);
    }
    printf("\n");
    return 0;
}
