/*
 https://cses.fi/problemset/task/1670
 Swap Game
 practice with Dukkha
 */
#include <stdio.h>

#define N    362880    /* N = 9! */

int ff[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int cc[9];

int rank() {
    int i, j, k = 0;
    
    for (i = 0; i < 9; i++) {
        int l = 0;
        
        for (j = i + 1; j < 9; j++)
            if (cc[j] < cc[i])
                l++;
        k += l * ff[8 - i];
    }
    return k;
}

void inc() {
    int i, j, tmp;
    
    i = 7;
    while (cc[i] > cc[i + 1])
        i--;
    j = i + 1;
    while (j + 1 < 9 && cc[j + 1] > cc[i])
        j++;
    tmp = cc[i], cc[i] = cc[j], cc[j] = tmp;
    for (i++, j = 8; i < j; i++, j--)
        tmp = cc[i], cc[i] = cc[j], cc[j] = tmp;
}

int aa[N][12];

void link(int i, int h, int u, int v) {
    int tmp;
    
    tmp = cc[u], cc[u] = cc[v], cc[v] = tmp;
    aa[i][h] = rank();
    tmp = cc[u], cc[u] = cc[v], cc[v] = tmp;
}

int main() {
    static int qq[N], dd[N];
    int h, i, j, t, r, c, u, head, cnt, d;
    
    for (h = 0; h < 9; h++)
        scanf("%d", &cc[h]);
    t = rank();
    if (t == 0) {
        printf("0\n");
        return 0;
    }
    for (h = 0; h < 9; h++)
        cc[h] = h;
    for (i = 0; i < N; i++) {
        h = 0;
        for (r = 0; r < 3; r++)
            for (c = 0; c < 3; c++) {
                u = r * 3 + c;
                if (r < 2)
                    link(i, h++, u, u + 3);
                if (c < 2)
                    link(i, h++, u, u + 1);
            }
        if (i + 1 < N)
            inc();
    }
    for (i = 0; i < N; i++)
        dd[i] = N;
    dd[0] = 0;
    head = cnt = 0;
    qq[head + cnt++] = 0;
    while (cnt) {
        i = qq[cnt--, head++];
        d = dd[i] + 1;
        for (h = 0; h < 12; h++)
            if (dd[j = aa[i][h]] > d) {
                dd[j] = d;
                if (j == t) {
                    printf("%d\n", d);
                    return 0;
                }
                qq[head + cnt++] = j;
            }
    }
    return 0;
}
