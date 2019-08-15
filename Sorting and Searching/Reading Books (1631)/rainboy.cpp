/*
 https://cses.fi/problemset/task/1631
 Reading Books
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int n;
    long long sum, max;
    
    scanf("%d", &n);
    sum = max = 0;
    while (n--) {
        int t;
        
        scanf("%d", &t);
        sum += t;
        if (max < t)
            max = t;
    }
    printf("%lld\n", max <= sum - max ? sum : max * 2);
    return 0;
}
