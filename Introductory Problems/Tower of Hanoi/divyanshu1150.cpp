#include<bits/stdc++.h>
using namespace std;

void solve(int n, int current, int help, int dest){
    //base case for 1 disk
    if(n == 1){
        cout << current << " " << dest << endl;
        return;
    }

    //solve for upper n-1 disk from current to help stack
    solve(n-1, current, dest, help);

    //move the largest disk to the distination
    cout << current << " " << dest << endl;

    //solve for remaining n-1 disk from help to destination
    solve(n-1, help, current, dest);
}

int main(){
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    int current = 1, help = 2, dest = 3;

    //transfer n disks from current stack to destination stack using help stack
    solve(n, current, help, dest);
    return 0;
}
