// https://cses.fi/problemset/task/1134
// Prüfer Code
// practice with rainboy
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 500000;

int aa[N], last[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &aa[i]);
        aa[i]--;
    }
    fill_n(last, n, -1);
    for (int i = 0; i < n - 2; i++)
        last[aa[i]] = i;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int a = 0; a < n; a++)
        if (last[a] == -1)
            pq.push(a);
    for (int i = 0; i < n - 2; i++) {
        int a = aa[i];
        int b = pq.top(); pq.pop();
        printf("%d %d\n", a + 1, b + 1);
        if (last[a] == i)
            pq.push(a);
    }
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    printf("%d %d\n", a + 1, b + 1);
}
