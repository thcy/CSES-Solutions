#include <bits/stdc++.h>
int column[8]={0}, d1[15]={0},d2[15]={0};
char c[8][8];
using namespace std;
int ans;
void rec(int q)
{
    if(!(q-8))
        ans++;
    else{
        for(int i=0;i<8;i++)
        {
            if(!( column[i] or d1[q+ i] or d2[7-q+i]) and c[q][i]=='.')
            {
                column[i] = d1[q+ i] = d2[7-q+i]=1;
                rec(q+1);
                column[i] = d1[q+ i] = d2[7-q+i]=0;
            }
        }
    }
     return;
}
int main() {
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	    cin>>c[i][j];
	rec(0);
    cout<<ans;
	return 0;
}
