#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a={2,3,10,6,4,8,1};
    func(a,a.size());
    return 0;
}
void func(vector<int>&a, int n)
{
    int mini=a[0];
    int ans=INT_MIN;
    int i;
    for(i=1;i<n;i++)
    {
        if(a[i]<mini)
        mini=a[i];
        else
        ans=max(ans, a[i]-mini);
    }
    cout<<"Maximum Difference with Largest appearing before then Smallest:\t"<<ans<<endl;
}