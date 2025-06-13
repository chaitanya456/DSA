#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,0,1,1,0,0,0,1,1};
    int n=a.size();
    int i,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        a[c]=a[i],c++;
    }
    for(i=c;i<n;i++)
    a[i]=0;
    for(auto x: a)
    cout<<x<<" ";
    return 0;
}