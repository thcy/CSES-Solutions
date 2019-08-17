/*
 https://cses.fi/problemset/task/1110/
 Minimal Rotation
 practice with Dukkha
 */
#include <stdio.h>
#include <string.h>

#define N    1000000

/* https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation */

char bb[N + N + 1];
int ff[N + N];

char *booth() {
    int n, i, j, k;
    
    n = strlen(bb);
    for (i = 0; i < n; i++)
        bb[i + n] = bb[i];
    memset(ff, -1, sizeof ff);
    k = 0;
    for (j = 1; j < n + n; j++) {
        i = ff[j - k - 1] + 1;
        while (bb[j] != bb[i + k]) {
            if (bb[j] < bb[i + k])
                k = j - i;
            if (i == 0) {
                i--;
                break;
            }
            i = ff[i - 1] + 1;
        }
        ff[j - k] = i;
    }
    bb[n + k] = '\0';
    return bb + k;
}

int main() {
    scanf("%s", bb);
    printf("%s\n", booth());
    return 0;
}
