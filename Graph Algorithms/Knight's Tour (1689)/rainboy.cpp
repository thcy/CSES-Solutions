/*
 https://cses.fi/problemset/task/1689
 Knight's Tour
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aa[8][8], hh[8][8][8], kk[8][8];

int di[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dj[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int dd[8];

int compare(const void *a, const void *b) {
    int u = *(int *) a;
    int v = *(int *) b;
    
    return dd[u] - dd[v];
}

int count(int i, int j) {
    int h, i_, j_, k;
    
    k = 0;
    for (h = 0; h < 8; h++) {
        i_ = i + di[h];
        j_ = j + dj[h];
        if (i_ >= 0 && i_ < 8 && j_ >= 0 && j_ < 8)
            k++;
    }
    return k;
}

void init() {
    static int hh_[8];
    int h, h_, i, i_, j, j_, k, tmp;
    
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            kk[i][j] = count(i, j);
    srand(time(NULL));
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++) {
            k = 0;
            for (h = 0; h < 8; h++) {
                i_ = i + di[h];
                j_ = j + dj[h];
                if (i_ >= 0 && i_ < 8 && j_ >= 0 && j_ < 8) {
                    dd[h] = kk[i_][j_];
                    hh_[k++] = h;
                }
            }
            kk[i][j] = k;
            for (h = 1; h < k; h++) {
                h_ = rand() % (h + 1);
                tmp = hh_[h], hh_[h] = hh_[h_], hh_[h_] = tmp;
            }
            qsort(hh_, k, sizeof *hh_, compare);
            for (h = 0; h < k; h++)
                hh[i][j][h] = hh_[h];
        }
}

int solve(int i, int j, int m) {
    int *hh_ = hh[i][j], h, i_, j_, k;
    
    if (aa[i][j])
        return 0;
    aa[i][j] = m;
    if (m == 64)
        return 1;
    m++;
    k = kk[i][j];
    for (h = 0; h < k; h++) {
        i_ = i + di[hh_[h]];
        j_ = j + dj[hh_[h]];
        if (solve(i_, j_, m))
            return 1;
    }
    aa[i][j] = 0;
    return 0;
}

int main() {
    int i1, j1, i, j;
    
    init();
    scanf("%d%d", &j1, &i1), j1--, i1--;
    solve(i1, j1, 1);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            printf("%d ", aa[i][j]);
        printf("\n");
    }
    return 0;
}
