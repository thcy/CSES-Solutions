/*
 https://cses.fi/problemset/task/1070
 Permutations
 */
#include <stdio.h>

int main() {
    int n, a;
    
    scanf("%d", &n);
    if (n == 2 || n == 3) {
        printf("NO SOLUTION\n");
        return 0;
    }
    for (a = 2; a <= n; a += 2)
    printf("%d ", a);
    for (a = 1; a <= n; a += 2)
    printf("%d ", a);
    printf("\n");
    return 0;
}
