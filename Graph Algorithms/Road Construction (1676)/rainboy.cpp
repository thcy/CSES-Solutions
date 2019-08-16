/*
 https://cses.fi/problemset/task/1676
 Road Construction
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000

int dsu[N];

int find(int i) {
    return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

int join(int i, int j) {
    int tmp;
    
    i = find(i);
    j = find(j);
    if (i == j)
        return 0;
    if (dsu[i] < dsu[j])
        tmp = i, i = j, j = tmp;
    dsu[j] += dsu[i];
    dsu[i] = j;
    return -dsu[j];
}

int main() {
    int n, m, i, j, c, c_;
    
    scanf("%d%d", &n, &m);
    memset(dsu, -1, n * sizeof *dsu);
    c_ = 1;
    while (m--) {
        scanf("%d%d", &i, &j), i--, j--;
        c = join(i, j);
        if (c != 0) {
            n--;
            if (c_ < c)
                c_ = c;
        }
        printf("%d %d\n", n, c_);
    }
    return 0;
}
