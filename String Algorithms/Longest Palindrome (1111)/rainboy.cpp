/*
 https://cses.fi/problemset/task/1111
 Longest Palindrome
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000
#define M    (N * 2 + 1)

int main() {
    static char cc[N + 1], aa[M + 1], s[N + 1];
    static int rr[M];
    int n, m, i, i_, o, x, r_, k;
    
    scanf("%s", cc);
    n = strlen(cc);
    m = n * 2 + 1;
    memset(aa, '_', m);
    for (i = 0; i < n; i++)
        aa[i * 2 + 1] = cc[i];
    o = 0, x = 1;
    rr[0] = x - o;
    for (i = 1; i < m; i++)
        if (o + o - i >= 0 && rr[o + o - i] < x - i)
            rr[i] = rr[o + o - i];
        else {
            o = i;
            if (x < i + 1)
                x = i + 1;
            while (x < m && o + o - x >= 0 && aa[o + o - x] == aa[x])
                x++;
            rr[i] = x - o;
        }
    i_ = 0;
    for (i = 1; i < m; i++)
        if (rr[i_] < rr[i])
            i_ = i;
    r_ = rr[i_];
    k = 0;
    for (i = i_ - r_ + 2; i <= i_ + r_ - 2; i += 2)
        s[k++] = aa[i];
    printf("%s\n", s);
    return 0;
}
