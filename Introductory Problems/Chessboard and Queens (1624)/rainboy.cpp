/*
 https://cses.fi/problemset/task/1624
 Chessboard and Queens
 practice with Dukkha
 */
#include <stdio.h>

char cc[8][9], col[8], d1[15], d2[15];
int cnt;

void solve(int i) {
    int j;
    
    if (i == 8) {
        cnt++;
        return;
    }
    for (j = 0; j < 8; j++)
        if (cc[i][j] == '.' && !col[j] && !d1[i + j] && !d2[i - j + 7]) {
            col[j] = d1[i + j] = d2[i - j + 7] = 1;
            solve(i + 1);
            col[j] = d1[i + j] = d2[i - j + 7] = 0;
        }
}

int main() {
    int i;
    
    for (i = 0; i < 8; i++)
        scanf("%s", cc[i]);
    solve(0);
    printf("%d\n", cnt);
    return 0;
}
