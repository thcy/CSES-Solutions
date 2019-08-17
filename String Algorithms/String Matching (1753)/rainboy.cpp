/*
 https://cses.fi/problemset/task/1753
 String Matching
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000
#define M    1000000
#define A    26

int main() {
    static char aa[N + 1], bb[M + 1];
    static int ff[M], dd[M + 1][A];
    int n, m, i, j, a, cnt;
    
    scanf("%s%s", aa, bb);
    n = strlen(aa);
    m = strlen(bb);
    ff[0] = -1;
    for (j = 1; j < m; j++) {
        i = ff[j - 1] + 1;
        while (bb[i] != bb[j]) {
            if (i == 0) {
                i = -1;
                break;
            }
            i = ff[i - 1] + 1;
        }
        ff[j] = i;
    }
    for (j = 0; j <= m; j++)
        for (a = 0; a < A; a++)
            if (j < m && bb[j] == a + 'a')
                dd[j][a] = j + 1;
            else
                dd[j][a] = j == 0 ? 0 : dd[ff[j - 1] + 1][a];
    cnt = 0;
    for (i = 0, j = 0; i < n; i++)
        if ((j = dd[j][aa[i] - 'a']) == m)
            cnt++;
    printf("%d\n", cnt);
    return 0;
}
