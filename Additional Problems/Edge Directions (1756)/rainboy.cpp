/*
 https://cses.fi/problemset/task/1756
 Edge Directions
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    while (m--) {
        int i, j, tmp;
        
        scanf("%d%d", &i, &j);
        if (i > j)
            tmp = i, i = j, j = tmp;
        printf("%d %d\n", i, j);
    }
    return 0;
}
