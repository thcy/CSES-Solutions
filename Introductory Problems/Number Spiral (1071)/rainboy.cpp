/*
 https://cses.fi/problemset/task/1071
 Number Spiral
 */
#include <stdio.h>

int main() {
    int t;
    
    scanf("%d", &t);
    while (t--) {
        int x, y, tmp;
        long long a;
        
        scanf("%d%d", &x, &y);
        a = x > y ? x : y;
        if (a % 2 == 1)
        tmp = x, x = y, y = tmp;
        printf("%lld\n", x > y ? a * a - (y - 1) : (a - 1) * (a - 1) + x);
    }
    return 0;
}
