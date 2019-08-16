/*
 https://cses.fi/problemset/task/1144
 Salaries
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000
#define Q    200000
#define K    (N + Q * 2)

char cc[Q];
int aa[Q], bb[Q];
int pp[K], ii[K], tt[K];

int compare(const void *a, const void *b) {
    int i = *(int *) a;
    int j = *(int *) b;
    
    return pp[i] - pp[j];
}

void update(int i, int n, int x) {
    while (i < n) {
        tt[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    
    while (i >= 0) {
        x += tt[i];
        i &= i + 1;
        i--;
    }
    return x;
}

int main() {
    int n, q, k, h, i, p;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &pp[i]);
    k = n;
    for (i = 0; i < q; i++) {
        static char s[2];
        int a, b;
        
        scanf("%s%d%d", s, &a, &b);
        if ((cc[i] = s[0]) == '?') {
            pp[aa[i] = k++] = a - 1;
            pp[bb[i] = k++] = b;
        } else {
            aa[i] = a - 1;
            pp[bb[i] = k++] = b;
        }
    }
    for (h = 0; h < k; h++)
        ii[h] = h;
    qsort(ii, k, sizeof *ii, compare);
    p = 0;
    for (h = 0; h < k; h++)
        pp[ii[h]] = h + 1 == k || pp[ii[h]] != pp[ii[h + 1]] ? p++ : p;
    for (i = 0; i < n; i++)
        update(pp[i], p, 1);
    for (i = 0; i < q; i++)
        if (cc[i] == '?')
            printf("%d\n", query(pp[bb[i]]) - query(pp[aa[i]]));
        else {
            update(pp[aa[i]], p, -1);
            update(pp[bb[i]], p, 1);
            pp[aa[i]] = pp[bb[i]];
        }
    return 0;
}
