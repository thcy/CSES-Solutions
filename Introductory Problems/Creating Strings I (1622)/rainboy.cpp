/*
 https://cses.fi/problemset/task/1622
 Creating Strings I
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N    8
#define K    40320

char *ss[K];
int k;

void solve(char *cc, int n) {
    int i;
    char tmp;
    
    if (n == 0) {
        ss[k++] = strdup(cc);
        return;
    }
    for (i = 0; i < n; i++) {
        tmp = cc[i], cc[i] = cc[n - 1], cc[n - 1] = tmp;
        solve(cc, n - 1);
        tmp = cc[i], cc[i] = cc[n - 1], cc[n - 1] = tmp;
    }
}

int compare(const void *a, const void *b) {
    char *s = *(char **) a;
    char *t = *(char **) b;
    
    return strcmp(s, t);
}

int main() {
    static char cc[N + 1];
    int n, k_, h;
    
    scanf("%s", cc);
    n = strlen(cc);
    solve(cc, n);
    qsort(ss, k, sizeof *ss, compare);
    k_ = 1;
    for (h = 1; h < k; h++)
        if (strcmp(ss[k_ - 1], ss[h]))
            ss[k_++] = ss[h];
    k = k_;
    printf("%d\n", k);
    for (h = 0; h < k; h++)
        printf("%s\n", ss[h]);
    return 0;
}
