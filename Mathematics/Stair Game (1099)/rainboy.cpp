/*
 https://cses.fi/problemset/task/1099
 Stair Game
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int t;
    
    scanf("%d", &t);
    while (t--) {
        int n, i, x, p;
        
        scanf("%d", &n);
        x = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &p);
            if (i % 2)
                x ^= p;
        }
        printf(x ? "first\n" : "second\n");
    }
    return 0;
}
