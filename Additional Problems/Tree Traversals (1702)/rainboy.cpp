/*
 https://cses.fi/problemset/task/1702
 Tree Traversals
 practice with Dukkha
 */
#include <stdio.h>

#define N    100000

int main() {
    static int pp[N + 2], aa[N + 2], ii[N + 2], s1[N + 2], s2[N + 2];
    int n, i, k1, k2;
    
    scanf("%d", &n);
    pp[0] = n;
    for (i = 1; i <= n; i++)
        scanf("%d", &pp[i]), pp[i]--;
    pp[n + 1] = n + 1;
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]), aa[i]--;
    aa[n] = n;
    aa[n + 1] = n + 1;
    for (i = 0; i < n + 2; i++)
        ii[aa[i]] = i;
    k1 = k2 = 0;
    s1[k1++] = pp[0];
    s2[k2++] = pp[0];
    for (i = 1; i < n + 2; i++) {
        int a = pp[i], b = pp[i - 1];
        
        if (ii[a] > ii[b]) {
            int p = -1, q = -1;
            
            while (k2 && ii[a] > ii[q = s2[k2 - 1]]) {
                p = q;
                k2--;
            }
            while ((q = s1[k1 - 1]) != p) {
                printf("%d ", q + 1);
                k1--;
            }
        }
        s1[k1++] = a;
        s2[k2++] = a;
    }
    printf("\n");
    return 0;
}
