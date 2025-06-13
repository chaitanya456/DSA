//This is O(NlogN) implementation of LIS 
#include<bits/stdc++.h>
using namespace std;
void lis(vector<int>&a, int n);
int main()
{
    vector<int> a={3, 10, 2, 1, 20};
    int n=a.size();
    lis(a,n);
    return 0;
}
void lis(vector<int>&a, int n)
{
    vector<int> ans;
    ans.push_back(a[0]);
    int i;
    for(i=1;i<n;i++)
    {
        if(a[i]>ans.back())
        ans.push_back(a[i]);
        else
        {
            auto low=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[low]=a[i];
        }
    }
    cout<<"Longest Increasing Subsequence:\t"<<ans.size()<<endl;
}