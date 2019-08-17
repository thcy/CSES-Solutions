/*
 https://cses.fi/problemset/task/1113
 String Transform
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

int main() {
    static char cc[N + 2], s[N + 1];
    static int kk[26], pp[N + 1], ii[N + 1];
    int n, i, c, k;
    
    scanf("%s", cc);
    n = strlen(cc) - 1;
    for (i = 0; i <= n; i++)
        if (cc[i] != '#')
            kk[cc[i] - 'a']++;
    for (c = 1; c < 26; c++)
        kk[c] += kk[c - 1];
    for (c = 25; c > 0; c--)
        kk[c] = kk[c - 1];
    kk[0] = 0;
    for (i = 0; i <= n; i++)
        if (cc[i] != '#')
            pp[i] = ++kk[cc[i] - 'a'];
    for (i = 0; i <= n; i++)
        ii[pp[i]] = i;
    k = 0;
    for (i = ii[0]; i != 0; i = ii[i])
        s[k++] = cc[ii[i]];
    printf("%s\n", s);
    return 0;
}
