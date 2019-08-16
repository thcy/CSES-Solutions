/*
 https://cses.fi/problemset/task/1684
 Giant Pizza
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    100000
#define M    100000

struct L {
    struct L *next;
    int j;
} aa[N * 2], bb[N * 2];

void link(int i, int j) {
    static struct L l91[M * 4], *l = l91;
    
    l->j = j;
    l->next = aa[i].next, aa[i].next = l++;
    l->j = i;
    l->next = bb[j].next, bb[j].next = l++;
}

int cc[N * 2], qq[N * 2];

void dfs1(int i) {
    static int cnt;
    struct L *l;
    
    if (cc[i])
        return;
    cc[i] = 1;
    for (l = aa[i].next; l; l = l->next)
        dfs1(l->j);
    qq[cnt++] = i;
}

void dfs2(int j, int c) {
    struct L *l;
    
    if (cc[j])
        return;
    cc[j] = c;
    for (l = bb[j].next; l; l = l->next)
        dfs2(l->j, c);
}

int main() {
    int m, n, h, i, j, c;
    
    scanf("%d%d", &m, &n);
    while (m--) {
        static char s[2], t[2];
        int u, v, up, um, vp, vm;
        
        scanf("%s%d%s%d", s, &u, t, &v), u--, v--;
        up = u * 2 + (s[0] == '+');
        um = u * 2 + (s[0] != '+');
        vp = v * 2 + (t[0] == '+');
        vm = v * 2 + (t[0] != '+');
        link(um, vp);
        link(vm, up);
    }
    for (i = 0; i < n * 2; i++)
        if (!cc[i])
            dfs1(i);
    memset(cc, 0, n * 2 * sizeof *cc);
    c = 0;
    for (h = n * 2 - 1; h >= 0; h--) {
        j = qq[h];
        if (!cc[j])
            dfs2(j, ++c);
    }
    for (i = 0; i < n * 2; i += 2)
        if (cc[i] == cc[i + 1]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    for (i = 0; i < n * 2; i += 2)
        printf("%c ", cc[i] < cc[i + 1] ? '+' : '-');
    printf("\n");
    return 0;
}
