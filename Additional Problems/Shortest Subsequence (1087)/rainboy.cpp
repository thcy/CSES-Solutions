/*
 https://cses.fi/problemset/task/1087
 Subsequence
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

int main() {
    static char cc[N + 1];
    int n, i, a, c, g, t, k;
    char x;
    
    scanf("%s", cc);
    n = strlen(cc);
    k = 0;
    a = c = g = t = -1;
    for (i = 0; i < n; i++) {
        x = cc[i];
        if (x == 'A')
            a = i;
        else if (x == 'C')
            c = i;
        else if (x == 'G')
            g = i;
        else
            t = i;
        if (a != -1 && c != -1 && g != -1 && t != -1) {
            cc[k++] = x;
            a = c = g = t = -1;
        }
    }
    if (a == -1)
        x = 'A';
    else if (c == -1)
        x = 'C';
    else if (g == -1)
        x = 'G';
    else
        x = 'T';
    cc[k++] = x;
    cc[k] = '\0';
    printf("%s\n", cc);
    return 0;
}
