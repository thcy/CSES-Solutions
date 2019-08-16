/*
 https://cses.fi/problemset/task/1197
 Cycle Finding
 practice with Dukkha
 */
#include <stdio.h>

#define N    2500
#define M    5000

int main() {
    static int aa[M], bb[M], cc[M], pp[N], ii[1 + N];
    static char used[N];
    static long long dd[N];
    int n, m, h, r, a, b, c, k;
    long long d;
    
    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++)
        scanf("%d%d%d", &aa[h], &bb[h], &cc[h]), aa[h]--, bb[h]--;
    for (r = 0; r < n; r++)
        for (h = 0; h < m; h++) {
            a = aa[h], b = bb[h], c = cc[h];
            d = dd[a] + c;
            if (dd[b] > d) {
                dd[b] = d;
                pp[b] = a;
                if (r == n - 1) {
                    while (!used[b]) {
                        used[b] = 1;
                        b = pp[b];
                    }
                    k = 0;
                    while (used[b]) {
                        used[b] = 0;
                        ii[k++] = b;
                        b = pp[b];
                    }
                    ii[k++] = b;
                    printf("YES\n");
                    while (k--)
                        printf("%d ", ii[k] + 1);
                    printf("\n");
                    return 0;
                }
            }
        }
    printf("NO\n");
    return 0;
}
