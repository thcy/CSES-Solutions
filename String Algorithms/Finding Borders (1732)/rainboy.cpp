/*
 https://cses.fi/problemset/task/1732
 Finding Borders
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

int main() {
    static char cc[N + 1];
    static int zz[N];
    int n, i, l, r;
    
    scanf("%s", cc);
    n = strlen(cc);
    for (i = 1, l = r = 0; i < n; i++)
        if (zz[i - l] < r - i)
            zz[i] = zz[i - l];
        else {
            l = i;
            if (r < l)
                r = l;
            while (r < n && cc[r] == cc[r - l])
                r++;
            zz[i] = r - l;
        }
    for (i = n - 1; i > 0; i--)
        if (zz[i] == n - i)
            printf("%d ", n - i);
    printf("\n");
    return 0;
}
