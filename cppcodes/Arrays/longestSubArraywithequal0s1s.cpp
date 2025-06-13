#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={1,0,1,1,1,0,0};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    int i,sum=0;
    int res=INT_MIN;
    unordered_map<int,int>m;
    for(i=0;i<n;i++)
    {
        if(a[i])
        sum++;
        else sum--;
        if(sum==0)
        res=i+1;
        if(m.find(sum)!=m.end())
        res=max(res,abs(i-m[sum]));
        else m[sum]=i;
    }
    cout<<"Length of Longest Subarray with equal number of zeroes and ones:\t"<<res<<endl;
}