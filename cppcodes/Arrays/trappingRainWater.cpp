#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&a, int n);
int main()
{
    vector<int>a={2,1,5,3,1,0,4};
    int n=a.size();
    cout<<"Maximum Water Trapped:\t"<<func(a,n);
    return 0;
}
int func(vector<int>&a, int n)
{
    vector<int>pre(n),suf(n);
    int i;
    pre[0]=a[0];
    suf[n-1]=a[n-1];
    for(i=1;i<n;i++)
    pre[i]=max(a[i],pre[i-1]);
    for(i=n-2;i>=0;i--)
    suf[i]=max(a[i],suf[i+1]);
    int water=0;
    for(i=1;i<n-1;i++)
    {
        int mini=min(pre[i],suf[i]);
        if(a[i]<mini)
        water+=mini-a[i];
    }
    return water;
}