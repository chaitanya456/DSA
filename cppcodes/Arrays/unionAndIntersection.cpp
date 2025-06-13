#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,3,4,4,5,6,6};
    vector<int>b={2,4,6,6};
    vector<int>u,i;
    set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(u));
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(i));
    //Remove Duplicates
    u.erase(unique(u.begin(),u.end()),u.end());
    i.erase(unique(i.begin(),i.end()),i.end());
    cout<<"Union:\t";
    for(auto x: u)
    cout<<x<<" ";
    cout<<"\nIntersection:\t";
    for(auto x:i)
    cout<<x<<' ';
    return 0;
}