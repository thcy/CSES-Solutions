/*
 https://cses.fi/problemset/task/1743
 String Reorder
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000
#define A    26

int main() {
    static char cc[N + 1];
    static int kk[A];
    int n, i, p, a, b, c;
    
    scanf("%s", cc);
    n = strlen(cc);
    for (i = 0; i < n; i++) {
        a = cc[i] - 'A';
        kk[a]++;
    }
    for (a = 0; a < A; a++)
        if (n < kk[a] * 2 - 1) {
            printf("-1\n");
            return 0;
        }
    p = -1;
    for (i = 0; i < n; i++) {
        a = 0;
        while (a < A && (a == p || kk[a] == 0))
            a++;
        b = 0;
        for (c = 1; c < A; c++)
            if (kk[b] < kk[c])
                b = c;
        a = a != b && n - i - 1 < kk[b] * 2 - 1 ? b : a;
        kk[a]--;
        cc[i] = a + 'A';
        p = a;
    }
    printf("%s\n", cc);
    return 0;
}
