#include<bits/stdc++.h>
using namespace std;
int maxCrossingSubSum(vector<int> a, int l, int m, int h);
int maxArraySubSum(vector<int>a, int l, int h);
int main()
{
    vector<int> arr = {2, 3, 4, 5, 7};
    int n=arr.size();
    cout<<"Maximum Array SubSum:\t"<<maxArraySubSum(arr,0,n-1);
    return 0;
}
int maxArraySubSum(vector<int>a, int l, int h)
{
    if(l>h)
    return 0;
    if(l==h)
    return a[l];
    int m=(l+h)/2;
    int ls=maxArraySubSum(a,l,m);
    int rs=maxArraySubSum(a,m+1,h);
    int cs=maxCrossingSubSum(a,l,m,h);
    return max(cs, max(ls,rs));
}
int maxCrossingSubSum(vector<int> a, int l, int m, int h)
{
    int ls=INT_MIN;
    int i;
    int s=0;
    for(i=m;i>=l;i--)
    {
        s+=a[i];
        ls=max(s,ls);
    }
    int rs=INT_MIN;
    s=0;
    for(i=m+1;i<=h;i++)
    {
        s+=a[i];
        rs=max(rs,s);
    }
    return (ls+rs);
}