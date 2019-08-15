/*
 https://cses.fi/problemset/task/1625
 Grid Paths
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

char used[9][9], path[49];
int cnt;

int only(int i, int j) {
    int k = 0;
    
    if (i == 7 && j == 1)
        return 0;
    if (!used[i - 1][j])
        k++;
    if (!used[i + 1][j])
        k++;
    if (!used[i][j - 1])
        k++;
    if (!used[i][j + 1])
        k++;
    return k == 1;
}

void solve(int i, int j, int h) {
    int u, d, l, r;
    char p;
    
    if (h == 48 || (i == 7 && j == 1)) {
        if (h == 48)
            cnt++;
        return;
    }
    u = !used[i - 1][j];
    d = !used[i + 1][j];
    l = !used[i][j - 1];
    r = !used[i][j + 1];
    if ((u && d && !l && !r) || (!u && !d && l && r))
        return;
    used[i][j] = 1;
    p = path[h++];
    if (u && only(i - 1, j)) {
        if (p == 'U' || p == '?')
            solve(i - 1, j, h);
        used[i][j] = 0;
        return;
    }
    if (d && only(i + 1, j)) {
        if (p == 'D' || p == '?')
            solve(i + 1, j, h);
        used[i][j] = 0;
        return;
    }
    if (l && only(i, j - 1)) {
        if (p == 'L' || p == '?')
            solve(i, j - 1, h);
        used[i][j] = 0;
        return;
    }
    if (r && only(i, j + 1)) {
        if (p == 'R' || p == '?')
            solve(i, j + 1, h);
        used[i][j] = 0;
        return;
    }
    if (u && (p == 'U' || p == '?'))
        solve(i - 1, j, h);
    if (d && (p == 'D' || p == '?'))
        solve(i + 1, j, h);
    if (l && (p == 'L' || p == '?'))
        solve(i, j - 1, h);
    if (r && (p == 'R' || p == '?'))
        solve(i, j + 1, h);
    used[i][j] = 0;
}

int main() {
    int i, j;
    
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            used[i][j] = i == 0 || i == 8 || j == 0 || j == 8;
    scanf("%s", path);
    solve(1, 1, 0);
    printf("%d\n", cnt);
    return 0;
}
