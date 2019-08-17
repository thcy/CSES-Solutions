/*
 https://cses.fi/problemset/task/1753
 String Matching
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000
#define M    1000000

int main() {
    static char aa[N + 1], bb[M + 1], cc[M + 1 + N + 1];
    static int ff[M + 1 + N];
    int n, m, i, j, cnt;
    
    scanf("%s%s", aa, bb);
    n = strlen(aa);
    m = strlen(bb);
    for (j = 0; j < m; j++)
        cc[j] = bb[j];
    for (i = 0; i < n; i++)
        cc[m + 1 + i] = aa[i];
    ff[0] = -1;
    cnt = 0;
    for (j = 1; j < m + 1 + n; j++) {
        i = ff[j - 1] + 1;
        while (cc[i] != cc[j]) {
            if (i == 0) {
                i = -1;
                break;
            }
            i = ff[i - 1] + 1;
        }
        ff[j] = i;
        if (i + 1 == m)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
