#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n,a,d;
    scanf("%d",&n);
    multiset <pair < int , int > >arrival;
    multiset < pair < int, int > >depart;
    vector < pair < int, int > > sch;
    map<int, int > room;
    multiset < pair < int, int > >::iterator itr;
    loop(i,n)
    {
        scanf("%d %d",&a,&d);
        sch.push_back(make_pair(a,d));
        arrival.insert(make_pair(a,i));
        depart.insert(make_pair(d,i));
    }
    int room_num=0;
    while(arrival.size())
    {
        ++room_num;
        int arr,ind,dept;
        itr=arrival.begin();
        while(true)
        {
            arr=(*itr).first;
            ind=(*itr).second;
 
            arrival.erase(itr);
            
            room[ind]=room_num;
            dept=sch[ind].second;
            depart.erase(depart.find(make_pair(dept,ind)));
 
            itr=arrival.upper_bound(make_pair(dept,10000000));
            if(itr==arrival.end())
                break;
        }
    }
    cout<<room_num<<endl;
    loop(i, sch.size() )
        cout<<room[i]<<' ';
