/*
 https://cses.fi/problemset/task/1754
 Coin Piles
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int t;
    
    scanf("%d", &t);
    while (t--) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        printf((a + b) % 3 == 0 && a * 2 >= b && b * 2 >= a ? "YES\n" : "NO\n");
    }
    return 0;
}
