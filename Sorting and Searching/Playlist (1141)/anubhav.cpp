#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n,len=0;
    scanf("%d",&n);
    int a[n];
    map <int, int > song;
    loop(i,n)
    {
        scanf("%d",a+i);
        song[ a[i] ]=0;
    }
    int j=0,i=0;
    loop(i,n)
    {
        j=max(j,song[a[i]]);
        len=max(len,i-j+1);
        song[a[i]]=i+1;
    }
    printf("%d",len);
    return 0;
}
