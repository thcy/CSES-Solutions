/*
 https://cses.fi/problemset/task/1083
 Missing Number
 */
#include <stdio.h>

#define N    200000

int main() {
    static char used[N + 1];
    int n, i, a;
    
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        used[a] = 1;
    }
    for (a = 1; a <= n; a++)
    if (!used[a])
    break;
    printf("%d\n", a);
    return 0;
}
