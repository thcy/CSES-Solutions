/*
 practice with Dukkha
 https://cses.fi/problemset/task/1192
 Counting Rooms
 */
#include <stdio.h>
#include <string.h>

#define N    1000

int dsu[N * N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return;
    if (dsu[i] > dsu[j])
        dsu[i] = j;
    else {
        if (dsu[i] == dsu[j])
            dsu[i]--;
        dsu[j] = i;
    }
}

int main() {
    static char cc[N][N + 1];
    int n, m, i, j, cnt;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", cc[i]);
    memset(dsu, -1, sizeof dsu);
    for (i = 0; i < n; i++)
        for (j = 1; j < m; j++)
            if (cc[i][j - 1] == '.' && cc[i][j] == '.')
                join(i * m + j - 1, i * m + j);
    for (i = 1; i < n; i++)
        for (j = 0; j < m; j++)
            if (cc[i - 1][j] == '.' && cc[i][j] == '.')
                join((i - 1) * m + j, i * m + j);
    cnt = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (cc[i][j] == '.' && dsu[i * m + j] < 0)
                cnt++;
    printf("%d\n", cnt);
    return 0;
}
