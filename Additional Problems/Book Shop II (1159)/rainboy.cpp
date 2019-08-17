/*
 https://cses.fi/problemset/task/1159
 Book Shop II
 practice with Dukkha
 */
#include <stdio.h>

#define N    100
#define X    100000

int dp_[X + 1], dq_[X + 1], *dp = dp_, *dq = dq_, hh[N], ss[N], kk[N];

int main() {
    int n, x, i;
    
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &hh[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &ss[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &kk[i]);
    for (i = 0; i < n; i++) {
        int *tmp, h = hh[i], s = ss[i], k = kk[i], k_, r, u, v;
        
        for (r = 0; r < h; r++) {
            static int qq[X + 1];
            int head = 0, cnt = 0;
            
            for (v = r; v <= x; v += h) {
                int y = dp[v] - v / h * s;
                
                while (cnt) {
                    u = qq[head + cnt - 1];
                    if (y < dp[u] - u / h * s)
                        break;
                    cnt--;
                }
                qq[head + cnt++] = v;
                u = qq[head];
                k_ = (v - u) / h;
                dq[v] = dp[u] + k_ * s;
                if (k_ == k)
                    head++, cnt--;
            }
        }
        tmp = dp, dp = dq, dq = tmp;
    }
    printf("%d\n", dp[x]);
    return 0;
}
