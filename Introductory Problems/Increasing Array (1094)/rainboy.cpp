/*
 https://cses.fi/problemset/task/1094
 Increasing Array
 */
#include <stdio.h>

int main() {
    int n, max, a;
    long long ans;
    
    scanf("%d", &n);
    max = 0;
    ans = 0;
    while (n--) {
        scanf("%d", &a);
        if (max < a)
        max = a;
        ans += max - a;
    }
    printf("%lld\n", ans);
    return 0;
}
