/*
 https://cses.fi/problemset/task/1149
 String Removals
 practice with Dukkha
 */
#include <stdio.h>

#define N    500000
#define MD    1000000007

int main() {
    static char cc[N + 1];
    static int kk[26];
    int i, k, c, kc;
    
    scanf("%s", cc);
    k = 0;
    for (i = 0; cc[i]; i++) {
        c = cc[i] - 'a';
        kc = kk[c];
        kk[c] = k + 1;
        k = (k + (kk[c] - kc) % MD) % MD;
    }
    printf("%d\n", (k + MD) % MD);
    return 0;
}
