/*
 https://cses.fi/problemset/task/1069
 Repetitions
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

int main() {
    static char cc[N + 1];
    int n, i, max, cnt;
    
    scanf("%s", cc);
    n = strlen(cc);
    max = cnt = 0;
    for (i = 0; i < n; i++)
    if (max < (cnt = i == 0 || cc[i - 1] != cc[i] ? 1 : cnt + 1))
    max = cnt;
    printf("%d\n", max);
    return 0;
}
