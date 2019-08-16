/*
 https://cses.fi/problemset/task/1722
 Fibonacci Numbers
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

void mult(int aa[][2], int bb[][2], int cc[][2]) {
    int i, j, k;
    
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
            int c = 0;
            
            for (k = 0; k < 2; k++)
                c = (c + (long long) aa[i][k] * bb[k][j]) % MD;
            cc[i][j] = c;
        }
}

void power(int aa[][2], int pp[][2], int tt[][2], long long k) {
    if (k == 0) {
        pp[0][0] = 1; pp[0][1] = 0;
        pp[1][0] = 0; pp[1][1] = 1;
        return;
    }
    if (k % 2 == 0) {
        power(aa, tt, pp, k / 2);
        mult(tt, tt, pp);
    } else {
        power(aa, pp, tt, k / 2);
        mult(pp, pp, tt);
        mult(tt, aa, pp);
    }
}

int main() {
    static int aa[2][2], pp[2][2], tt[2][2];
    long long n;
    
    scanf("%lld", &n);
    aa[0][0] = 0; aa[0][1] = 1;
    aa[1][0] = 1; aa[1][1] = 1;
    power(aa, pp, tt, n);
    printf("%d\n", pp[0][1]);
    return 0;
}
