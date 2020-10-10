#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long a[n];
    bool pos=0;
    loop(i,n)
    {
        scanf("%lld",a+i);
        if(a[i]>0)
            pos=1;
    }
    long long max_end=0, max_so_far=0;
    if(pos)
    {
        loop(i,n)
        {
            max_end+=a[i];
            if(max_end<0)
                max_end=0;
            if(max_so_far<max_end)
                max_so_far=max_end;
        }
    }
    else{
        max_so_far=-1000000000;
        loop(i,n)
        if(max_so_far<a[i])
        max_so_far=a[i];
    }
    printf("%lld",max_so_far);
    return 0;
}
