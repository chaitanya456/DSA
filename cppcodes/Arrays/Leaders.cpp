#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={16,17,4,3,5,2};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    vector<int>res;
    int maxRight=a[n-1];
    res.push_back(maxRight);
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>=maxRight)
        {
            maxRight=a[i];
            res.push_back(maxRight);
        }
    }
    reverse(res.begin(),res.end());
    cout<<"Leaders:\t";
    for(auto x: res)
    cout<<x<<" ";
}