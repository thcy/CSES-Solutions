#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 500001;

int n, lst[MX], a[MX], ad[MX];
priority_queue<int,vi,greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) lst[i] = -1;
    F0R(i,n-2) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    FOR(i,1,n+1) {
        if (lst[i] == -1) pq.push(i);
        else ad[lst[i]] = i;
    }
    F0R(i,n-2) {
        cout << pq.top() << " " << a[i] << "\n";
        pq.pop();
        if (ad[i]) pq.push(ad[i]);
    }
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
