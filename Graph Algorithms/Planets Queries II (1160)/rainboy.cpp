/*
 https://cses.fi/problemset/task/1160
 Teleporters
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>

#define N    200000

int main() {
    static int aa[N], cc[N], mm[1 + N], dd[N], hh[N], *pp[N], ll[N], bb[N];
    int *qq, n, q, h, i, j, k, l, m, c, c_, d, d_;
    
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &aa[i]), aa[i]--;
    c_ = 0;
    for (i = 0; i < n; i++) {
        if (cc[i])
            continue;
        j = i;
        while (!cc[j]) {
            cc[j] = -1;
            j = aa[j];
        }
        if (cc[j] == -1) {
            c = ++c_;
            d = 0;
            h = 0;
            while (cc[j] == -1) {
                cc[j] = c;
                hh[j] = h++;
                j = aa[j];
            }
            mm[c] = h;
        } else {
            c = cc[j];
            d = dd[j];
        }
        j = i;
        m = 0;
        while (cc[j] == -1) {
            cc[j] = c;
            bb[m++] = j;
            j = aa[j];
        }
        bb[m] = j;
        for (h = m - 1; h >= 0; h--) {
            j = bb[h];
            d_ = dd[j] = d + m - h;
            l = 0;
            while (1 << (l + 1) <= d_)
                l++;
            qq = (int *) malloc((l + 1) * sizeof *qq);
            qq[0] = bb[h + 1];
            for (k = 1; k <= l; k++)
                qq[k] = pp[qq[k - 1]][k - 1];
            pp[j] = qq;
            ll[j] = l;
        }
    }
    while (q--) {
        int ans;
        
        scanf("%d%d", &i, &j), i--, j--;
        if (cc[i] != cc[j] || dd[i] < dd[j]) {
            printf("-1\n");
            continue;
        }
        d = dd[i] - dd[j];
        if (d)
            for (l = ll[i]; l >= 0; l--)
                if (1 << l <= dd[i] - dd[j])
                    i = pp[i][l];
        ans = 0;
        if (dd[i])
            ans = i == j ? d : -1;
        else {
            h = hh[j] - hh[i];
            if (h < 0)
                h += mm[cc[i]];
            ans = d + h;
        }
        printf("%d\n", ans);
    }
    return 0;
}
