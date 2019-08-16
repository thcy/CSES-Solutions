/*
 https://cses.fi/problemset/task/1730
 Nim Game I
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int t;
    
    scanf("%d", &t);
    while (t--) {
        int n, x, y;
        
        scanf("%d", &n);
        y = 0;
        while (n--)
            scanf("%d", &x), y ^= x;
        printf(y ? "first\n" : "second\n");
    }
    return 0;
}
