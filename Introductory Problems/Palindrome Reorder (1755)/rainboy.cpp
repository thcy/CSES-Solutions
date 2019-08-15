/*
 https://cses.fi/problemset/task/1755
 Palindrome Reorder
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

int main() {
    static char cc[N + 1];
    static int kk[26];
    int n, i, j, c, c_;
    
    scanf("%s", cc);
    n = strlen(cc);
    for (i = 0; i < n; i++)
        kk[cc[i] - 'A']++;
    c_ = -1;
    for (c = 0; c < 26; c++)
        if (kk[c] % 2 == 1) {
            if (c_ == -1)
                c_ = c;
            else {
                printf("NO SOLUTION\n");
                return 0;
            }
        }
    for (i = 0, j = n - 1, c = 0; c < 26; c++)
        while (kk[c] >= 2) {
            cc[i++] = cc[j--] = c + 'A';
            kk[c] -= 2;
        }
    if (c_ != -1)
        cc[i++] = c_ + 'A';
    printf("%s\n", cc);
    return 0;
}
