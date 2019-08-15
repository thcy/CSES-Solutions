/*
 https://cses.fi/problemset/task/1645
 Nearest Smaller Values
 practice with Dukkha
 */
#include <stdio.h>

#define N    200000

int main() {
    static int aa[N + 1], stack[N + 1];
    int n, h, i, cnt;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &aa[i]);
    cnt = 0;
    stack[cnt++] = 0;
    for (i = 1; i <= n; i++) {
        while (aa[h = stack[cnt - 1]] >= aa[i])
            cnt--;
        printf("%d ", h);
        stack[cnt++] = i;
    }
    printf("\n");
    return 0;
}
