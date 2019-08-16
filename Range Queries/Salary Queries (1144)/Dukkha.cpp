// https://cses.fi/problemset/task/1144
// Salaries
// practice with rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000, Q = N;

int pp[N + Q * 2], ii[N + Q * 2];
char cc[N];
int aa[N], bb[N];

int tt[N + Q * 2];

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
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &pp[i]);
    int k = n;
    for (int i = 0; i < q; i++) {
        char s[2];
        int a, b;
        scanf("%s%d%d", s, &a, &b);
        cc[i] = s[0];
        if (cc[i] == '?') {
            pp[aa[i] = k++] = a - 1;
            pp[bb[i] = k++] = b;
        } else {
            aa[i] = a - 1;
            pp[bb[i] = k++] = b;
        }
    }
    for (int h = 0; h < k; h++)
        ii[h] = h;
    sort(ii, ii + k, [] (int i, int j) { return pp[i] < pp[j]; });
    int p = 0;
    for (int h = 0; h < k; h++)
        pp[ii[h]] = h + 1 == k || pp[ii[h]] != pp[ii[h + 1]] ? p++ : p;
    for (int i = 0; i < n; i++)
        update(pp[i], p, 1);
    for (int i = 0; i < q; i++)
        if (cc[i] == '?')
            printf("%d\n", query(pp[bb[i]]) - query(pp[aa[i]]));
        else {
            update(pp[aa[i]], p, -1);
            update(pp[bb[i]], p, 1);
            pp[aa[i]] = pp[bb[i]];
        }
}
