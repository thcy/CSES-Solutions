/*
 https://cses.fi/problemset/task/1157
 Number Grid
 practice with Dukkha
 */
#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d%d", &x, &y);
    printf("%d\n", (x - 1) ^ (y - 1));
    return 0;
}
