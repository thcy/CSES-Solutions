/*
 https://cses.fi/problemset/task/1700
 Tree Isomorphism I
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N    100000
#define MD    1000000007

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
    return (rand() * 45677LL + rand()) % n;
}

struct L {
    struct L *next;
    int j;
} aa[N];

int xx[N], yy[N], xx_[N], yy_[N];

void link(int i, int j) {
    static struct L l91[N * 2 * 2], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
}

int dfs(int p, int i) {
    struct L *l;
    int j, h_, h, x, y, x_, y_;
    
    h_ = -1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p)
            if (h_ < (h = dfs(i, j)))
                h_ = h;
    h_++;
    x = xx[h_], x_ = 1;
    y = yy[h_], y_ = 1;
    for (l = aa[i].next; l; l = l->next)
        if ((j = l->j) != p) {
            x_ = (long long) x_ * (x + xx_[j]) % MD;
            y_ = (long long) y_ * (y + yy_[j]) % MD;
        }
    xx_[i] = x_;
    yy_[i] = y_;
    return h_;
}

int main() {
    int t;
    
    init_rand();
    scanf("%d", &t);
    while (t--) {
        static long long hh[2];
        int n, h, i, j, k;
        
        scanf("%d", &n);
        xx[0] = 1;
        yy[0] = 1;
        for (h = 1; h < n; h++) {
            xx[h] = rand_(MD - 2) + 2;
            yy[h] = rand_(MD - 2) + 2;
        }
        for (k = 0; k < 2; k++) {
            for (i = 0; i < n; i++)
                aa[i].next = NULL;
            for (h = 0; h < n - 1; h++) {
                scanf("%d%d", &i, &j), i--, j--;
                link(i, j);
                link(j, i);
            }
            dfs(-1, 0);
            hh[k] = (long long) xx_[0] * MD + yy_[0];
        }
        printf(hh[0] == hh[1] ? "YES\n" : "NO\n");
    }
    return 0;
}
