/*
 https://cses.fi/problemset/task/1096
 Throwing Dice
 practice with Dukkha
 */
#include <stdio.h>

#define MD    1000000007

void mult(int aa[][6], int bb[][6], int cc[][6]) {
    int i, j, k;
    
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++) {
            int c = 0;
            
            for (k = 0; k < 6; k++)
                c = (c + (long long) aa[i][k] * bb[k][j]) % MD;
            cc[i][j] = c;
        }
}

void power(int aa[][6], int pp[][6], int tt[][6], long long n) {
    int i, j;
    
    if (n == 0) {
        for (i = 0; i < 6; i++)
            for (j = 0; j < 6; j++)
                pp[i][j] = i == j;
        return;
    }
    if (n % 2 == 0) {
        power(aa, tt, pp, n / 2);
        mult(tt, tt, pp);
    } else {
        power(aa, pp, tt, n / 2);
        mult(pp, pp, tt);
        mult(tt, aa, pp);
    }
}

int main() {
    static int aa[6][6], pp[6][6], tt[6][6];
    long long n;
    
    scanf("%lld", &n);
    aa[0][1] = aa[1][2] = aa[2][3] = aa[3][4] = aa[4][5] = 1;
    aa[5][0] = aa[5][1] = aa[5][2] = aa[5][3] = aa[5][4] = aa[5][5] = 1;
    power(aa, pp, tt, n);
    printf("%d\n", pp[5][5]);
    return 0;
}
