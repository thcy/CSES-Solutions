/*
 https://cses.fi/problemset/task/1731
 Word Combinations
 practice with Dukkha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N    5000
#define M    200000
#define K    100000
#define MD    1000000007

void init_rand() {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec ^ tv.tv_usec);
}

int P, Q;

long long hash(char *s, int n) {
    long long x, y;
    
    x = y = 0;
    while (n--) {
        x = (x * P + *s) % MD;
        y = (y * Q + *s) % MD;
        s++;
    }
    return x * MD + y;
}

int aa[N + 1], bb[N + 1], pp[N + 1], qq[N + 1];

long long hash2(int i, int j) {
    long long x = (aa[j] - (long long) aa[i - 1] * pp[j - i + 1] % MD) % MD;
    long long y = (bb[j] - (long long) bb[i - 1] * qq[j - i + 1] % MD) % MD;
    
    if (x < 0)
        x += MD;
    if (y < 0)
        y += MD;
    return x * MD + y;
}

struct L {
    struct L *next;
    long long key;
} hs[M];

struct L *new_L(long long key) {
    static struct L l91[K], *l = l91;
    
    l->key = key;
    return l++;
}

void hs_put(long long key) {
    struct L *l = new_L(key);
    int h = (key % M + M) % M;
    
    l->next = hs[h].next; hs[h].next = l;
}

int hs_contains(long long key) {
    struct L *l;
    int h = (key % M + M) % M;
    
    for (l = hs[h].next; l; l = l->next)
        if (key == l->key)
            return 1;
    return 0;
}

int compare(const void *a, const void *b) {
    int ia = *(int *) a;
    int ib = *(int *) b;
    
    return ia - ib;
}

int main() {
    static char cc[1048576], used[N + 1];
    static int ll[N + 1], dp[N + 1];
    int n, h, i, j, k, l, m, x;
    
    init_rand();
    P = (rand() * 45677LL + rand()) % (MD - 2) + 2;
    Q = (rand() * 45677LL + rand()) % (MD - 2) + 2;
    scanf("%s", cc);
    n = strlen(cc);
    aa[0] = bb[0] = 0;
    pp[0] = qq[0] = 1;
    for (i = 0; i < n; i++) {
        aa[i + 1] = ((long long) aa[i] * P + cc[i]) % MD;
        bb[i + 1] = ((long long) bb[i] * Q + cc[i]) % MD;
        pp[i + 1] = (long long) pp[i] * P % MD;
        qq[i + 1] = (long long) qq[i] * Q % MD;
    }
    scanf("%d", &k);
    m = 0;
    while (k--) {
        scanf("%s", cc);
        l = strlen(cc);
        if (l <= n && !used[l]) {
            ll[m++] = l;
            used[l] = 1;
        }
        hs_put(hash(cc, l));
    }
    qsort(ll, m, sizeof *ll, compare);
    dp[0] = 1;
    for (i = 0; i < n; i++) {
        x = dp[i];
        if (x == 0)
            continue;
        for (h = 0; h < m && (j = i + ll[h]) <= n; h++)
            if (hs_contains(hash2(i + 1, j)))
                dp[j] = (dp[j] + x) % MD;
    }
    printf("%d\n", dp[n]);
    return 0;
}
