/*
 https://cses.fi/problemset/task/1617
 Bit Strings
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

int main() {
    int n, ans;
    
    scanf("%d", &n);
    ans = 1;
    while (n--)
    ans = ans * 2 % MD;
    printf("%d\n", ans);
    return 0;
}
