/*
 https://cses.fi/problemset/task/1092
 Two Sets
 */
#include <stdio.h>

int main() {
    int n, i;
    
    scanf("%d", &n);
    if (n % 4 == 1 || n % 4 == 2) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (n % 4 == 0) {
        printf("%d\n", n / 2);
        for (i = 1; i < n + 1 - i; i += 2)
        printf("%d %d ", i, n + 1 - i);
        printf("\n");
        printf("%d\n", n / 2);
        for (i = 2; i < n + 1 - i; i += 2)
        printf("%d %d ", i, n + 1 - i);
        printf("\n");
    } else {
        printf("%d\n", n / 2 + 1);
        printf("1 2 ");
        for (i = 4; i < n + 4 - i; i += 2)
        printf("%d %d ", i, n + 4 - i);
        printf("\n");
        printf("%d\n", n / 2);
        printf("3 ");
        for (i = 5; i < n + 4 - i; i += 2)
        printf("%d %d ", i, n + 4 - i);
        printf("\n");
    }
    return 0;
}
