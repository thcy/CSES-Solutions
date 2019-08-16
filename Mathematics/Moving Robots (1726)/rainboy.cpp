/*
 https://cses.fi/problemset/task/1726
 Moving Robots
 practice with Dukkha
 */
#include <stdio.h>

#define N    64

void mult(double aa[][N], double bb[][N], double cc[][N]) {
    int i, j, k;
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            double c = 0;
            
            for (k = 0; k < N; k++)
                c += aa[i][k] * bb[k][j];
            cc[i][j] = c;
        }
}

void power(double aa[][N], double pp[][N], double tt[][N], int k) {
    if (k == 0) {
        int i, j;
        
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                pp[i][j] = i == j;
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
    static double aa[N][N], pp[N][N], tt[N][N];
    int k, h, i, j, r, c, m;
    double ans, x;
    
    scanf("%d", &k);
    for (r = 0; r < 8; r++)
        for (c = 0; c < 8; c++) {
            h = r * 8 + c;
            m = 0;
            if (r > 0) m++;
            if (r < 7) m++;
            if (c > 0) m++;
            if (c < 7) m++;
            x = 1.0 / m;
            if (r > 0) aa[(r - 1) * 8 + c][h] = x;
            if (r < 7) aa[(r + 1) * 8 + c][h] = x;
            if (c > 0) aa[r * 8 + c - 1][h] = x;
            if (c < 7) aa[r * 8 + c + 1][h] = x;
        }
    power(aa, pp, tt, k);
    ans = 0;
    for (i = 0; i < N; i++) {
        double x = 1;
        
        for (j = 0; j < N; j++)
            x *= 1 - pp[i][j];
        ans += x;
    }
    printf("%.6f\n", ans);
    return 0;
}
