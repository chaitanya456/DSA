#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a={10,3,5,6,2};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    vector<int>pre(n,1),suf(n,1);
    int i;
    for(i=1;i<n;i++)
    pre[i]=pre[i-1]*a[i-1];
    for(i=n-2;i>=0;i--)
    suf[i]=suf[i+1]*a[i+1];
    vector<int>res;
    for(i=0;i<n;i++)
    res.push_back(pre[i]*suf[i]);
    cout<<"Multiplying Without Self:\t";
    for(auto x: res)
    cout<<x<<" ";
}