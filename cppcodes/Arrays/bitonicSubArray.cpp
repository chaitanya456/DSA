#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a,int n);
int main()
{
    vector<int>a={12,4,78,90,45,23};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a,int n)
{
    vector<int>l(n);
    vector<int>d(n);
    int i;
    l[0]=d[n-1]=1;
    for(i=1;i<n;i++)
    l[i]=(a[i]>=a[i-1])?l[i-1]+1:1;
    for(i=n-2;i>=0;i--)
    d[i]=(a[i]>=a[i+1])?d[i+1]+1:1;
    int m=l[0]+d[0]-1;
    for(i=1;i<n;i++)
    if(l[i]+d[i]-1>m)
    m=l[i]+d[i]-1;
    cout<<"Maximum Bitonic Subarray Length:\t"<<m<<endl;
}